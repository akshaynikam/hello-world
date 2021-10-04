#include <iostream>
#include <queue>
#include <stack>
#include <set>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

void insert(node **root, int data) {
    if (*root == NULL) {
        *root = new node();
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if ((*root)->data <= data) insert(&(*root)->right, data);
    else insert(&(*root)->left, data);
}

void add_left(stack<node*>& st, node* n) {
    while (n) {
        st.push(n);
        n = n->left;
    }
}

void inorder(node* root) {
    stack<node*> st;

    add_left(st, root);
    while (!st.empty()) {
        node* cur = st.top();
        st.pop();
        cout << cur->data << " ";
        add_left(st, cur->right);
    }

    cout << endl;
}

void preorder(node* root) {
    stack<node*> st;

    st.push(root);

    while (!st.empty()) {
        node* cur = st.top();
        st.pop();
        cout << cur->data << " ";
        if (cur->right) st.push(cur->right);
        if (cur->left) st.push(cur->left);
    }

    cout << endl;
}

void postorder(node* root) {
    stack<node*> s1, s2;
    s1.push(root);
    while (!s1.empty()) {
        node* cur = s1.top();
        s2.push(cur);
        s1.pop();
        if (cur->left) s1.push(cur->left);
        if (cur->right) s1.push(cur->right);
    }

    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }

    cout << endl;
}

int main() {
    node* root = NULL;

    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 6);
    insert(&root, 8);

    inorder(root);
    postorder(root);
    preorder(root);

    return 0;
}
