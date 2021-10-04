#include <iostream>

using namespace std;

class stack {
    struct node {
        int data;
        node *next;
    };

    node* head;
public:
    stack() {
        head = NULL;
    }

    bool empty() {
        return head == NULL;
    }

    void push(int data) {
        node* newnode = new node;
        newnode->data = data;
        newnode->next = head;
        head = newnode;
    }

    void pop() {
        if (head) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    int top() {
        if (head) return head->data;
        return -1;
    }

    void print() {
        node* cur = head;
        while (cur) {
            cout << cur->data << " ";
            cur = cur->next;
        }

        cout << endl;
    }

    void sort() {
        stack temp;

        while (!empty()) {
            int ele = top();
            pop();
            while (!temp.empty() && ele > temp.top()) {
                push(temp.top());
                temp.pop();
            }

            temp.push(ele);
        }

        while (!temp.empty()) {
            push(temp.top());
            temp.pop();
        }
    }
};

int main() {
    stack st;

    st.push(50);
    st.push(30);
    st.push(70);
    st.push(20);
    st.push(40);
    st.push(80);
    st.push(10);
    st.push(60);

    st.print();
    st.sort();
    st.print();

    return 0;
}
