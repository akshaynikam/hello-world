#include <iostream>
#include "stack_auto.hpp"

int main() {
    Stack<int, 3> intStack;
    
    intStack.push(11);
    intStack.push(22);
    intStack.push(33);

    std::cout << intStack.top() << std::endl;
    intStack.pop();
    std::cout << intStack.top() << std::endl;
    intStack.pop();
    std::cout << intStack.top() << std::endl;
    intStack.pop();

    Stack<std::string, 3> strStack; // size_type = int
    Stack<double, 3u> dblStack;     // size_type = unsigned int

    auto intStSize = intStack.size();
    auto strStSize = strStack.size();
    auto dblStSize = dblStack.size();
    if (std::is_same<decltype(intStSize), decltype(strStSize)>::value)
        std::cout << "intStackSize type is same as strStackSize type\n";
    else
        std::cout << "intStackSize type is not same as strStackSize type\n";

    if (std::is_same_v<decltype(intStSize), decltype(dblStSize)>)
        std::cout << "intStackSize type is same as dblStackSize type\n";
    else
        std::cout << "intStackSize type is not same as dblStackSize type\n";

    return 0;
}