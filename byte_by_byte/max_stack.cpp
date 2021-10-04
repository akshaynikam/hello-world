#include <iostream>

class stack {
    struct node {
        int data;
        node* next;
        int old_max;
    };

    node* head;
    int max;

public:
    stack() {
        head = NULL;
        max = -1;
    }

    void push(int data) {
        node* newnode = new node();
        newnode->data = data;
        newnode->next = head;
        head = newnode;

        if (newnode->data > max) {
            newnode->old_max = max;
            max = newnode->data;
        }
    }

    int pop() {
        int data = -1;
        if (head) {
            data = head->data;
            node* top = head;
            head = head->next;

            if (top->data == max) {
                max = top->old_max;
            }
            delete top;
        }

        return data;
    }

    int maxS() {
        return max;
    }
};

int main() {
    stack st;

    st.push(11);
    st.push(33);
    st.push(22);
    st.push(60);
    st.push(50);
    st.push(23);

    std::cout << "max : " << st.maxS() << std::endl;
    std::cout << "pop : " << st.pop() << std::endl;
    std::cout << "max : " << st.maxS() << std::endl;
    std::cout << "pop : " << st.pop() << std::endl;
    std::cout << "max : " << st.maxS() << std::endl;
    std::cout << "pop : " << st.pop() << std::endl;
    std::cout << "max : " << st.maxS() << std::endl;
    std::cout << "pop : " << st.pop() << std::endl;
    std::cout << "max : " << st.maxS() << std::endl;
    std::cout << "pop : " << st.pop() << std::endl;
    std::cout << "max : " << st.maxS() << std::endl;
    std::cout << "pop : " << st.pop() << std::endl;
    std::cout << "max : " << st.maxS() << std::endl;
    std::cout << "pop : " << st.pop() << std::endl;

    return 0;
}
