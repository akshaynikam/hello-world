#include <iostream>
#include "stack_nontype.hpp"

int main() {
    Stack<int, 3> intStack;
    Stack<std::string, 3> strStack;

    intStack.push(100);
    intStack.push(200);
    intStack.push(300);
    std::cout << intStack.top() << std::endl;
    intStack.pop();
    std::cout << intStack.top() << std::endl;
    intStack.pop();
    std::cout << intStack.top() << std::endl;
    intStack.pop();
    // intStack.pop();     // Assertion

    strStack.push("Akshay");
    strStack.push("Nikam");
    strStack.push("Patil");
    // strStack.push("Patil"); // Assertion
    std::cout << strStack.top() << std::endl;
    strStack.pop();
    std::cout << strStack.top() << std::endl;
    strStack.pop();
    std::cout << strStack.top() << std::endl;
    strStack.pop();


    return 0;
}