#include <iostream>

using namespace std;

struct BinaryTree {
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

struct stacking {
    stacking* back;
    stacking* forward;
    BinaryTree* link_tree;
};

void add_tree(BinaryTree*& root, int a) {
    if (root == nullptr) {
        root = new BinaryTree;
        root->data = a;
        root->left = nullptr;
        root->right = nullptr;
        return;
    }
    else {
        if (a > root->data) {
            add_tree(root->right, a);
        }
        else {
            add_tree(root->left, a);
        }
    }
}

void data_in(BinaryTree*& root) {
    int a = 1;
    while (a != 0) {
        cin >> a;
        if (a == 0) {
            break;
        }
        add_tree(root, a);
    }
    return;
}

void add_jam(BinaryTree* root, stacking*& queue_last) {
    if (root != nullptr) {
        if (root->left != nullptr && root->right != nullptr) {
            stacking* tmp_1 = new stacking;
            //if (root->left == nullptr) {
            //    tmp_1->link_tree
            //}
            tmp_1->link_tree = root->left;
            stacking* tmp_2 = new stacking;
            tmp_2->link_tree = root->right;
            tmp_1->forward = tmp_2;
            tmp_2->back = tmp_1;
            queue_last->forward = tmp_1;
            tmp_1->back = queue_last;
            queue_last = tmp_2;
        }
        if (root->right != nullptr && root->left == nullptr) {
            stacking* tmp_2 = new stacking;
            tmp_2->link_tree = root->right;
            queue_last->forward = tmp_2;
            tmp_2->back = queue_last;
            queue_last = tmp_2;
        }
        if (root->left != nullptr && root->right == nullptr) {
            stacking* tmp_2 = new stacking;
            tmp_2->link_tree = root->left;
            queue_last->forward = tmp_2;
            tmp_2->back = queue_last;
            queue_last = tmp_2;
        }
        //stacking* tmp_3 = new stacking;
        //tmp_3->forward = nullptr;
        //queue_last->forward = tmp_3;
        //tmp_3->back = queue_last;
        //tmp_3->link_tree = nullptr;
    }
}

void delete_jam(BinaryTree* root, stacking*& queue_first) {
    stacking* tmp = queue_first;
    queue_first = queue_first->forward;
    delete tmp;
}

void level_iteration(BinaryTree* root, stacking*& queue_first, stacking*& queue_last) {
    if (root == nullptr) {
        return;
    }
    stacking* tmp = queue_first;
    stacking* tmp_last = queue_last;
    //cout << queue_last->back->forward<<"aa";
    //cout << tmp_last->back->forward;
    while (tmp != nullptr) { //!=tmp_last(?)
        //cout << "AA"<<tmp << tmp_last << tmp->link_tree->data << tmp_last->link_tree->data << "AA"<<'\n';
        //cout << queue_first->forward->link_tree->data;
        cout << tmp->link_tree->data << " ";
        if (tmp!=nullptr && tmp->link_tree != nullptr) {
            add_jam(tmp->link_tree, queue_last);
        }
        //cout << queue_last->back->link_tree->data;
        //cout << tmp_last->back->forward->link_tree->data;
        if (tmp->link_tree->data == tmp_last->back->link_tree->data) {
            break;
        }
        tmp = tmp->forward;
    }
    queue_first = tmp_last;//->back->forward;
    //cout << '\n' << queue_first;
}

void data_out(BinaryTree* root) {
    if (root == nullptr) {
        return;
    }
    stacking* queue_first = new stacking;
    stacking* queue_last = new stacking;
    queue_first->link_tree = root;
    queue_first->forward = queue_last;
    queue_first->back = nullptr;
    queue_last->back = queue_first;
    queue_last->link_tree = root;
    while (true) {
        level_iteration(root, queue_first, queue_last);
        cout << '\n';
    }
}

void delete_tree(BinaryTree* root) {
    if (root == nullptr) {
        delete root;
        return;
    }
    else {
        delete_tree(root->left);
        delete_tree(root->right);
        delete root;
    }
}

int main() {
    BinaryTree* root = nullptr;
    data_in(root);
    data_out(root);
    delete_tree(root);
}