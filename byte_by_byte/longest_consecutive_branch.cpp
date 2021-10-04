#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

int consecutive(node* root, int prev, int length) {
    if (root == NULL) return length;
    if (root->data == prev + 1) {
        int left = consecutive(root->left, root->data, length + 1);
        int right = consecutive(root->right, root->data, length + 1);
        return max(left, right);
    } else {
        int left = consecutive(root->left, root->data, length);
        int right = consecutive(root->right, root->data, length);
        return max(max(left, right), length);
    }
}

int longest_branch_length(node* root) {
    if (root == NULL) return 0;
    return max(consecutive(root->left, root->data, 1),
               consecutive(root->right, root->data, 1));
}

int main() {
    node* root = new node();
    root->data = 0;
    root->left = new node();
    root->left->data = 1;
    root->left->left = new node();
    root->left->left->data = 1;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->right = new node();
    root->left->right->data = 2;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->right = new node();
    root->right->data = 2;
    root->right->left = new node();
    root->right->left->data = 1;
    root->right->left->left = NULL;
    root->right->left->right = NULL;
    root->right->right = new node();
    root->right->right->data = 3;
    root->right->right->left = NULL;
    root->right->right->right = NULL;

    cout << longest_branch_length(root) << endl;

    return 0;
}
