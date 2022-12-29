#include <deque>
#include <iostream>

template <typename T>
class stack {
    private:
        std::deque<T> elems;
    public:
        void push(T const& ele) { elems.push_back(ele); }
        void pop() { elems.pop_back(); }
        T const& top() const { return elems.back(); }
        bool empty() const { return elems.empty(); }

        template <typename T2>
        stack& operator=(stack<T2> const&);
};

template <typename T>
template <typename T2>
stack<T>& stack<T>::operator=(stack<T2> const& op) {
    stack<T2> tmp(op);

    elems.clear();
    while (!tmp.empty()) {
        elems.push_front(tmp.top());
        tmp.pop();
    }

    return *this;
}

int main() {
    stack<int> intS1, intS2;
    stack<float> floatS;

    intS1 = intS2;
    floatS = intS1;

    return 0;
}