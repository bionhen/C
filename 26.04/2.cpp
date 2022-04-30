#include <iostream>
using namespace std;

struct BinaryTree {
    int data;
    int balance;
    BinaryTree* left;
    BinaryTree* right;
};

int height_count(BinaryTree*& root) {
    if (root == nullptr) {
        return 0;
    }
    int l_height = height_count(root->left);
    int r_height = height_count(root->right);
    if (l_height > r_height) {
        return l_height + 1;
    }
    else {
        return r_height + 1;
    }
}

void balance_count(BinaryTree*& root) {
    if (root != nullptr) {
        root->balance = height_count(root->right) - height_count(root->left);
    }
}

void right_turn(BinaryTree*& root) {
    BinaryTree* lst;
    BinaryTree* rlst;
    lst = root->left;
    rlst = lst->right;
    lst->right = root;
    root->left = rlst;
    root = lst;
    balance_count(root->right);
    balance_count(root);
}

void left_turn(BinaryTree*& root) {
    BinaryTree* rst;
    BinaryTree* lrst;
    rst = root->right;
    lrst = rst->left;
    rst->left = root;
    root->right = lrst;
    root = rst;
    balance_count(root->left);
    balance_count(root);
}

void add_tree(BinaryTree*& root, int a) {
    if (root == nullptr) {
        root = new BinaryTree;
        root->data = a;
        root->balance = 0;
        root->left = nullptr;
        root->right = nullptr;
    }
    else {
        if (a > root->data) {
            add_tree(root->right, a);
            if (height_count(root->right) - height_count(root->left) > 1) {
                if (height_count(root->right->right) < height_count(root->right->left)) {
                    right_turn(root->right);
                }
                left_turn(root);
            }
        }
        else {
            if (a < root->data) {
                add_tree(root->left, a);
                if (height_count(root->left) - height_count(root->right) > 1) {
                    if (height_count(root->left->left) < height_count(root->left->right)) {
                        left_turn(root->left);
                    }
                    right_turn(root);
                }
            }
            balance_count(root);
        }
    }
}

void data_out(BinaryTree* root) {
    if (root == nullptr) {
        return;
    }
    cout << "(";
    data_out(root->left);
    cout << root->data;
    data_out(root->right);
    cout << ")";
}

void data_in(BinaryTree*& root) {
    int a = 1;
    while (a != 0) {
        cin >> a;
        if (a == 0) {
            break;
        }
        add_tree(root, a);
        height_count(root);
        data_out(root);
        cout << '\n';
    }
    return;
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

