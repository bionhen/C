#include <iostream>
using namespace std;

struct BinaryTree {
    int data;
    BinaryTree* left;
    BinaryTree* right;
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

void data_in(BinaryTree* &root) {
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