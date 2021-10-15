#include <iostream>
#include <queue>

using namespace std;

struct node {
    node* left;
    node* right;
    int data;
};

void insert(node** head, int data) {
    if (NULL == *head) {
        *head = new node;
        (*head)->left = NULL;
        (*head)->right = NULL;
        (*head)->data = data;
    } else if ((*head)->data > data)
        insert(&(*head)->left, data);
    else
        insert(&(*head)->right, data);
}

void inorder(node* root, queue<node*>& q) {
    if (root) {
        inorder(root->left, q);
        q.push(root);
        inorder(root->right, q);
    }
}

node* create_doubly_linked_list(node* root) {
    queue<node*> q;

    inorder(root, q);
    node* prev = NULL;
    root = q.front();
    while (!q.empty()) {
        node* cur = q.front();
        q.pop();
        cur->left = prev;
        if (prev) prev->right = cur;
        prev = cur;
    }

    if (prev) prev->right = NULL;

    return root;
}

void print(node* root) {
    node* start = root;
    while (root) {
        cout << root->data << " ";
        root = root->right;
        if (root == start) break;
    }

    cout << endl;
}

void print_r(node* root) {
    while (root->right) root = root->right;

    while (root) {
        cout << root->data << " ";
        root = root->left;
    }

    cout << endl;
}

node* concat(node* a, node* b) {
    if (NULL == a) return b;
    if (NULL == b) return a;

    node* aEnd = a->left;
    node* bEnd = b->left;

    a->left = bEnd;
    bEnd->right = a;
    aEnd->right = b;
    b->left = aEnd;

    return a;
}

node* tree_to_list(node* root) {
    if (NULL == root) return NULL;
    node* left_list = tree_to_list(root->left);
    node* right_list = tree_to_list(root->right);

    root->left = root;
    root->right = root;

    root = concat(left_list, root);
    root = concat(root, right_list);

    return root;
}

int main() {
    node* root = NULL;

    insert(&root, 4);
    insert(&root, 2);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 6);
    insert(&root, 7);
    insert(&root, 5);

    //root = create_doubly_linked_list(root);
    root = tree_to_list(root);
    print(root);
    //print_r(root);

    return 0;
}
