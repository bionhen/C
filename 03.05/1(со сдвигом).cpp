#include <iostream>

using namespace std;

struct BinaryTree {
    int data;
    BinaryTree* left;
    BinaryTree* right;
};

struct stacking {
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

void add_jam(BinaryTree* root, stacking** queue_first) {
    stacking* current = *queue_first;
    stacking* previos = nullptr;
    stacking* new_elem = new stacking;
    if (root == nullptr) {
        BinaryTree* n = new BinaryTree;
        n->data = 0;
        n->left = n->right = nullptr;
        new_elem->link_tree = n;
    }
    else {
        new_elem->link_tree = root;
    }
    new_elem->forward = nullptr;
    while (current != nullptr) {
        previos = current;
        current = current->forward;
    }
    if (previos != nullptr) {
        previos->forward = new_elem;
    }
    else {
        *queue_first = new_elem;
    }
}

BinaryTree* out(stacking** queue_first) {
    stacking* old = *queue_first;
    BinaryTree * old_tree = nullptr;
    old_tree = old->link_tree;
    *queue_first = (*queue_first)->forward;
    delete old;
    return old_tree;
}


void queue_out(BinaryTree* root) {
    stacking* queue_first = nullptr;
    const int length = 40;
    int level = 0;
    int count_zero = 0;
    int count_elements = 0;
    bool out_pr = true;
    add_jam(root, &queue_first);
    while (queue_first != nullptr) {
        root = out(&queue_first);
        if (root->data == 0) {
            count_zero++;
        }
        else {
            count_zero = 0;
        }
        count_elements++;
        if (out_pr == true) {
            for (int i = 0; i < length - pow(2, level); i++) {
                cout << " ";
            }
            out_pr = false;
        }
        if (root->data != 0) {
            cout << root->data<<" ";
        }
        else{
            cout << "-  ";
        }
        if (pow(2, level) == count_elements) {
            level++;
            cout << '\n';
            if (count_elements == count_zero) {
                break;
            }
            count_elements = 0;
            count_zero = 0;
            out_pr = true;
        }
        add_jam(root->left, &queue_first);
        add_jam(root->right, &queue_first);
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
    queue_out(root);
    delete_tree(root);
}

