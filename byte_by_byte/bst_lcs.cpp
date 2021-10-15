#include <iostream>
#include <set>
#include <stack>

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

node* lcs(node* u, node* v) {
    set<node*> s;

    while (u->parent) {
        s.insert(u->parent);
        u = u->parent;
    }

    while (s.end() == s.find(v->parent)) v = v->parent;

    return v->parent;
}

node* search(node* head, int data) {
    if (head == NULL) return NULL;
    if (head->data == data) return head;
    if (head->data > data) return search(head->left, data);
    return search(head->right, data);
}

stack<node*> path(node* root, node* n) {
    if (root == NULL) return stack<node*>();
    if (root == n) {
        stack<node*> st;
        st.push(root);
        return st;
    }

    stack<node*> ls = path(root->left, n);
    stack<node*> rs = path(root->right, n);

    if (!ls.empty()) {
        ls.push(root);
        return ls;
    }

    if (!rs.empty()) {
        rs.push(root);
        return rs;
    }

    return stack<node*>();
}

node* lcs(node* root, node* n1, node* n2) {
    stack<node*> n1s = path(root, n1);
    stack<node*> n2s = path(root, n2);

    node* prev = NULL;
    while (n1s.top() == n2s.top()) {
        prev = n1s.top();
        n1s.pop();
        n2s.pop();
    }

    return prev;
}

int main() {
    node* root = NULL;

    insert(&root, NULL, 5);
    insert(&root, NULL, 2);
    insert(&root, NULL, 7);
    insert(&root, NULL, 1);
    insert(&root, NULL, 3);
    insert(&root, NULL, 6);
    insert(&root, NULL, 8);

    node* temp = lcs(root, search(root, 2), search(root, 8));

    cout << temp->data << endl;
    
    //stack<node*> st = path(root, search(root, 6));

    //while (!st.empty()) {
    //    cout << st.top()->data << " ";
    //    st.pop();
    //}

    cout << endl;

    return 0;
}
