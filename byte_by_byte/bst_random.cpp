#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct node {
    node* left;
    node* right;
    int data;
    int children;
};

void insert(node** head, int data) {
    if (NULL == *head) {
        *head = new node;
        (*head)->left = NULL;
        (*head)->right = NULL;
        (*head)->data = data;
        (*head)->children = 0;
    } else if ((*head)->data > data) {
        insert(&(*head)->left, data);
        (*head)->children++;
    }
    else {
        insert(&(*head)->right, data);
        (*head)->children++;
    }
}

void inorder(node* head) {
    if (head) {
        inorder(head->left);
        //cout << head->data << " : " << head->children << endl;;
        cout << head->data << " ";// << head->children << endl;;
        inorder(head->right);
    }
}

int get_children(node* root) {
    if (root) return root->children + 1;
    return 0;
}

int get_random(node* root, int index) {
    if (index == get_children(root->left)) return root->data;
    if (index < get_children(root->left)) return get_random(root->left, index);

    return get_random(root->right, index - get_children(root->left) - 1);
}

int get_random(node* root) {

    int index = rand() % (root->children + 1);

    return get_random(root, index);
}

int main() {
    node* root = NULL;

    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 3);
    insert(&root, 6);
    insert(&root, 8);

    //inorder(root);
    //cout << endl;

    srand(time(0));
    cout << get_random(root) << endl;
    cout << get_random(root) << endl;
    cout << get_random(root) << endl;
    cout << get_random(root) << endl;
    cout << get_random(root) << endl;
    cout << get_random(root) << endl;
    cout << get_random(root) << endl;

    return 0;
}
