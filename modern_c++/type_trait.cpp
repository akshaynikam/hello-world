#include <iostream>

// remove_reference trait removes referencesness of parameter
// typename std::remove_reference<T>::type()    C++11
// std::remove_reference_t<T>()                 C++14
template <typename T>
void fun(T&& v) {
    // If lvalue of type int is passed then T will be deduced to be int&, which is not integral type
    // References aren't integral types
    std::cout << "type of parameter without type trait: " << std::is_integral<T>() << std::endl;
    std::cout << "type of parameter (C++14) type trait: " << std::is_integral<std::remove_reference_t<T>>() << std::endl;
    std::cout << "type of parameter (C++11) type trait: " << std::is_integral<typename std::remove_reference<T>::type>() << std::endl;
}

int main() {
    int i = 0;

    fun(i);
    fun(10);

    return 0;
}