#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct node {
    node* left;
    node* right;
    int data;
};

void print_level_wise(node* root) {
    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* cur = q.front();
        q.pop();
        if (cur) {
            cout << cur->data << " ";
            q.push(cur->right);
            q.push(cur->left);
        }
    }

    cout << endl;
}

int balanced(node* root) {
    if (root == NULL) return 0;
    int h1 = balanced(root->left);
    int h2 = balanced(root->right);

    if (h1 == -1 || h2 == -1) return -1;
    if (abs(h1 - h2) > 1) return -1;
    if (h1 > h2) return h1 + 1;
    return h2 + 1;
}

bool is_bbt(node* root) {
    if (root == NULL) return true;
    if (balanced(root) > -1) return true;
    return false;
}

int main() {
    node* valid = NULL;

    valid = new node();
    valid->data = 1;
    valid->left = new node();
    valid->left->data = 2;
    valid->left->left = new node();
    valid->left->left->data = 4;
    valid->left->left->left = new node();
    valid->left->left->left->data = 8;
    valid->left->left->left->left = NULL;
    valid->left->left->left->right = NULL;
    valid->left->left->right = NULL;
    valid->left->right = new node();
    valid->left->right->data = 5;
    valid->left->right->left = NULL;
    valid->left->right->right = NULL;

    valid->right = new node();
    valid->right->data = 3;
    valid->right->left = new node();
    valid->right->left->data = 6;
    valid->right->left->left = new node();
    valid->right->left->left->data = 9;
    valid->right->left->left->left = NULL;
    valid->right->left->left->right = new node();
    valid->right->left->left->right->data = 13;
    valid->right->left->left->right->left = NULL;
    valid->right->left->left->right->right = NULL;
    valid->right->left->right = new node();
    valid->right->left->right->data = 10;
    valid->right->left->right->left = NULL;
    valid->right->left->right->right = NULL;
    valid->right->right = new node();
    valid->right->right->data = 7;
    valid->right->right->left = new node();
    valid->right->right->left->data = 11;
    valid->right->right->left->left = NULL;
    valid->right->right->left->right = NULL;
    valid->right->right->right = new node();
    valid->right->right->right->data = 12;
    valid->right->right->right->left = NULL;
    valid->right->right->right->right = NULL;

    node* invalid = NULL;

    invalid = new node();
    invalid->data = 1;
    invalid->left = new node();
    invalid->left->data = 2;
    invalid->left->left = new node();
    invalid->left->left->data = 4;
    invalid->left->left->left = new node();
    invalid->left->left->left->data = 8;
    invalid->left->left->left->left = NULL;
    invalid->left->left->left->right = NULL;
    invalid->left->left->right = NULL;
    invalid->left->right = new node();
    invalid->left->right->data = 5;
    invalid->left->right->left = NULL;
    invalid->left->right->right = NULL;

    invalid->right = new node();
    invalid->right->data = 3;
    invalid->right->left = new node();
    invalid->right->left->data = 6;
    invalid->right->left->left = new node();
    invalid->right->left->left->data = 9;
    invalid->right->left->left->left = NULL;
    invalid->right->left->left->right = new node();
    invalid->right->left->left->right->data = 13;
    invalid->right->left->left->right->left = new node();
    invalid->right->left->left->right->left->left = NULL;
    invalid->right->left->left->right->left->right = NULL;
    invalid->right->left->left->right->right = NULL;
    invalid->right->left->right = new node();
    invalid->right->left->right->data = 10;
    invalid->right->left->right->left = NULL;
    invalid->right->left->right->right = NULL;
    invalid->right->right = new node();
    invalid->right->right->data = 7;
    invalid->right->right->left = new node();
    invalid->right->right->left->data = 11;
    invalid->right->right->left->left = NULL;
    invalid->right->right->left->right = NULL;
    invalid->right->right->right = new node();
    invalid->right->right->right->data = 12;
    invalid->right->right->right->left = NULL;
    invalid->right->right->right->right = NULL;

    //print_level_wise(valid);

    cout << is_bbt(valid) << endl;
    cout << is_bbt(invalid) << endl;

    return 0;
}
