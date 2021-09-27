#include <iostream>
#include <set>
#include <stack>

using namespace std;

class linked_list {
    struct node {
        node *next;
        int val;
    };

    node* head;
    int count;
    node* getNewNode(int data) {
        node* temp = new node();
        temp->val = data;
        temp->next = NULL;
    }
public:
    linked_list() {
        head = NULL;
        count = 0;
    }
    void insert(int data);
    int remove(int data);
    void print();
    void print_reverse();
    int get_nth_to_last(int n);
    bool is_list_palindrome();
    void dedup();
};

void linked_list::dedup() {
    set<int> hash;
    node* cur = head;
    node* prev = NULL;

    while (cur) {
        if (hash.end() != hash.find(cur->val)) {
            prev->next = cur->next;
            delete cur;
            count--;
            cur = prev->next;
        } else {
            hash.insert(cur->val);
            prev = cur;
            cur = cur->next;
        }
    }
}

void linked_list::print_reverse() {
    stack<int> st;

    node* cur = head;

    while (cur) {
        st.push(cur->val);
        cur = cur->next;
    }

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

bool linked_list::is_list_palindrome() {
    stack<int> st;
    node* cur = head;

    while (cur) {
        st.push(cur->val);
        cur = cur->next;
    }

    cur = head;
    while (cur) {
        if (cur->val != st.top()) return false;
        st.pop();
        cur = cur->next;
    }

    return true;
}

int linked_list::get_nth_to_last(int n) {
    if (n >= count) return -1;
    int nth = count - n - 1;

    node* cur = head;
    while (nth--) cur = cur->next;
    return cur->val;
}

void linked_list::insert(int data) {
    node* newnode = getNewNode(data);
    if (head == NULL)
        head = newnode;
    else {
        newnode->next = head;
        head = newnode;
    }
    count++;
}

int linked_list::remove(int data) {
    node* cur = head;
    node* prev = NULL;
    int ret = -1;

    while (cur && cur->val != data) {
        prev = cur;
        cur = cur->next;
    }

    if (cur) {
        if (prev) {
            prev->next = cur->next;
        } else {
            head = cur->next;
        }

        ret = cur->val;
        count--;
        delete cur;
    }

    return ret;
}

void linked_list::print() {
    node* cur = head;

    while (cur) {
        cout << cur->val << " ";
        cur = cur->next;
    }

    cout << endl;
}

int main() {
    linked_list ll;
    ll.insert(10);
    ll.insert(20);
    ll.insert(30);
    ll.insert(40);
    ll.insert(50);

    ll.print();
    //ll.print_reverse();

    //cout << ll.get_nth_to_last(0) << endl;
    //cout << ll.get_nth_to_last(1) << endl;
    //cout << ll.get_nth_to_last(2) << endl;
    //cout << ll.get_nth_to_last(3) << endl;
    //cout << ll.get_nth_to_last(4) << endl;
    //cout << ll.get_nth_to_last(5) << endl;

    //cout << ll.is_list_palindrome() << endl;
    ll.insert(50);
    ll.insert(40);
    ll.insert(30);
    ll.insert(20);
    ll.insert(10);

    ll.print();
    ll.dedup();
    ll.print();
    //cout << ll.is_list_palindrome() << endl;
    return 0;
}
