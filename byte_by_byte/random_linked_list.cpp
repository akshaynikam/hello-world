#include <iostream>
#include <map>

using namespace std;

struct node {
    int val;
    node* next;
    node* random;
};

void print(node* head) {
    while (head) {
        cout << head->val << " --> " << head->random->val << endl;
        cout << "|" << endl;
        head = head->next;
    }

    cout << "null\n";
}

node* clone(node* head) {
    map<node*, node*> hash;
    node* n = head;
    node* copy = new node();
    copy->next = NULL;

    node* cur = copy;
    hash[n] = cur;
    while (n->next) {
        cur->next = new node();
        hash[n->next] = cur->next;
        cur = cur->next;
        n = n->next;
        cur->next = NULL;
    }

    cur = copy;
    n = head;
    while (n) {
        cur->val = n->val;
        cur->random = hash[n->random];
        n = n->next;
        cur = cur->next;
    }

    return copy;
}

int main() {
    node* head = new node();
    node* last = head;

    head->val = 1;
    
    last->next = new node();
    last->next->val = 2;
    last = last->next;
    last->random = head;

    last->next = new node();
    last->next->val = 3;
    last = last->next;
    last->random = last;

    last->next = new node();
    last->next->val = 4;
    last = last->next;
    last->random = head->next;
    last->next = NULL;

    head->random = head->next->next;

    print(head);

    node* copy = clone(head);
    print(copy);

    return 0;
}
