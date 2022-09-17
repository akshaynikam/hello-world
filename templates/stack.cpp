#include <iostream>
#include <vector>
#include <cassert>

template <typename T>
class Stack {
    std::vector<T> elems;

    public:
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const {
            return elems.empty();
        }        
};

template <typename T>
void Stack<T>::push(T const& elem) {
    elems.push_back(elem);
}

template <typename T>
void Stack<T>::pop() {
    assert(!elems.empty());

    elems.pop_back();
}

template <typename T>
T const& Stack<T>::top() const {
    assert(!elems.empty());

    return elems.back();
}

int main() {
    Stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    std::cout << s.top() << std::endl;  // 4
    s.pop();                            // remove 4
    std::cout << s.top() << std::endl;  // 3
    s.pop();                            // remove 3
    std::cout << s.top() << std::endl;  // 2
    s.pop();                            // remove 2
    std::cout << s.top() << std::endl;  // 1
    s.pop();                            // remove 1
    std::cout << s.top() << std::endl;  // assert
    s.pop();                            // assert

    return 0;
}