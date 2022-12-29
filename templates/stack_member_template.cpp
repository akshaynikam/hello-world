#include <deque>
#include <iostream>

template<typename T>
class Stack {
    std::deque<T> elems;
    public:
        void push(T const&);
        void pop();
        T const& top();
        bool empty() { return elems.empty(); }
        template<typename T2>
        Stack& operator= (Stack<T2> const&);
};

template<typename T>
void Stack<T>::push(T const& e) {
    elems.push_back(e);
}

template<typename T>
void Stack<T>::pop() {
    elems.pop_back();
}

template<typename T>
T const& Stack<T>::top() {
    return elems.back();
}

template<typename T>
    template<typename T2>
Stack<T>& Stack<T>::operator=(Stack<T2> const& op2) {
    Stack<T2> tmp(op2);
    elems.clear();

    while (!tmp.empty()) {
        elems.push_front(tmp.top());
        tmp.pop();
    }

    return *this;
}

int main() {
    Stack<int> si1;
    Stack<float> si2;

    si1.push(11);
    si1.push(22);
    si1.push(33);
    si1.push(44);

    si2 = si1;

    std::cout << si2.top() << std::endl;
    si2.pop();
    std::cout << si2.top() << std::endl;
    si2.pop();
    std::cout << si2.top() << std::endl;
    si2.pop();
    std::cout << si2.top() << std::endl;
    si2.pop();

    return 0;
}