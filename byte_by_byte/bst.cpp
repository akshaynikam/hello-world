#include <iostream>

using namespace std;

struct node {
    node* parent;
    node* left;
    node* right;
    int data;
};

void insert(node** head, node* parent, int data) {
    if (NULL == *head) {
        *head = new node;
        (*head)->left = NULL;
        (*head)->right = NULL;
        (*head)->parent = parent;
        (*head)->data = data;
    } else if ((*head)->data > data)
        insert(&(*head)->left, *head, data);
    else
        insert(&(*head)->right, *head, data);
}

void inorder(node* head) {
    if (head) {
        inorder(head->left);
        cout << head->data << " ";
        inorder(head->right);
    }
}

node* search(node* head, int data) {
    if (head == NULL) return NULL;
    if (head->data == data) return head;
    if (head->data > data) return search(head->left, data);
    return search(head->right, data);
}

void insert(node** head, int data) {
    insert(head, NULL, data);
}

node* predecessor(node* cur) {
    if (NULL == cur) return NULL;

    node* temp = NULL;
    if (cur->left) {
        temp = cur->left;
        while (temp->right) temp = temp->right;
    } else {
        temp = cur->parent;
        while (temp && temp->right != cur) {
            cur = temp;
            temp = temp->parent;
        }
    }

    return temp;
}

node* successor(node* cur) {
    if (NULL == cur) return NULL;

    node* temp = NULL;
    if (cur->right) {
        temp = cur->right;
        while (temp->left) temp = temp->left;
    } else {
        temp = cur->parent;
        while (temp && temp->left != cur) {
            cur = temp;
            temp = temp->parent;
        }
    }

    return temp;
}

node* get_min(node* head) {
    while (head->left) head = head->left;
    return head;
}

node* get_max(node* head) {
    while (head->right) head = head->right;
    return head;
}

void sum(node* head, int k) {
    node* left = get_min(head);
    node* right = get_max(head);

    while (left && right && (left->data <= right->data)) {
        if (k == left->data + right->data) {
            cout << k << " = " << left->data << " + " << right->data << endl;
            return;
        } else if (k < (left->data + right->data)) right = predecessor(right);
        else left = successor(left);
    }
}

int main() {
    node* head = NULL;
    
    insert(&head, 10);
    insert(&head, 5);
    insert(&head, 14);
    insert(&head, 16);
    insert(&head, 11);
    insert(&head, 13);

    inorder(head);
    cout << endl;

    sum(head, 30);

    return 0;
}
