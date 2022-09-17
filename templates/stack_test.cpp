#include <iostream>
#include <deque>
#include "stack_default_arg.hpp"

int main() {
    Stack<int> vecStack;
    Stack<int, std::deque<int>> deqStack;

    vecStack.push(11);
    vecStack.push(12);
    vecStack.push(13);

    deqStack.push(21);
    deqStack.push(22);
    deqStack.push(23);

    std::cout << "vecStack.top() : " << vecStack.top() << std::endl;
    vecStack.pop();
    std::cout << "vecStack.top() : " << vecStack.top() << std::endl;
    vecStack.pop();
    std::cout << "vecStack.top() : " << vecStack.top() << std::endl;
    vecStack.pop();

    std::cout << "deqStack.top() : " << deqStack.top() << std::endl;
    deqStack.pop();
    std::cout << "deqStack.top() : " << deqStack.top() << std::endl;
    deqStack.pop();
    std::cout << "deqStack.top() : " << deqStack.top() << std::endl;
    deqStack.pop();


    Stack<int> vecStackCPP11 = vecStack;    // OK in all versions
    Stack vecStackCPP17 = vecStack;         // OK Since C++17, error in previous versions
    Stack stringStack {"Akshay"};           // Stack<char const *> -> Stack<std::string> deduced since C++17

    std::cout << "stringStack.top() : " << stringStack.top() << std::endl;

    return 0;
}