#include <iostream>

using namespace std;

struct node {
    node* left;
    node* right;
    int data;
};

bool is_bst(node* root) {
    if (root == NULL) return true;
    bool left = true;
    bool right = true;

    if (root->left) {
        left = root->data > root->left->data;
    }

    if (root->right) {
        right = root->data < root->right->data;
    }

    return left && right && is_bst(root->left) && is_bst(root->right);
}

int main() {
    node* valid = NULL;

    valid = new node();
    valid->data = 5;
    valid->left = new node();
    valid->left->data = 2;
    valid->left->left = new node();
    valid->left->left->data = 1;
    valid->left->left->left = NULL;
    valid->left->left->right = NULL;

    valid->left->right = new node();
    valid->left->right->data = 3;
    valid->left->right->left = NULL;
    valid->left->right->right = NULL;

    valid->right = new node();
    valid->right->data = 7;
    valid->right->left = new node();
    valid->right->left->data = 6;
    valid->right->left->left = NULL;
    valid->right->left->right = NULL;

    valid->right->right = new node();
    valid->right->right->data = 8;
    valid->right->right->left = NULL;
    valid->right->right->right = NULL;

    node* invalid = NULL;

    invalid = new node();
    invalid->data = 5;
    invalid->left = new node();
    invalid->left->data = 2;
    invalid->left->left = new node();
    invalid->left->left->data = 1;
    invalid->left->left->left = NULL;
    invalid->left->left->right = NULL;

    invalid->left->right = new node();
    invalid->left->right->data = 3;
    invalid->left->right->left = NULL;
    invalid->left->right->right = NULL;

    invalid->right = new node();
    invalid->right->data = 7;
    invalid->right->left = new node();
    invalid->right->left->data = 6;
    invalid->right->left->left = NULL;
    invalid->right->left->right = NULL;

    invalid->right->right = new node();
    invalid->right->right->data = 4;
    invalid->right->right->left = NULL;
    invalid->right->right->right = NULL;

    cout << is_bst(valid) << endl;
    cout << is_bst(invalid) << endl;

    return 0;
}
