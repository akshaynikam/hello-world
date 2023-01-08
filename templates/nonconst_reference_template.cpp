#include <iostream>

template<typename T,
         typename = std::enable_if_t<!std::is_const<T>::value>>
void f(T& arg) {
    std::cout << arg << std::endl;
}

int main() {
    int i = 10;
    const int ci = 20;

    f(i);
    //f(ci);            // error: no matching function for call to ‘f(const int&)’....   Will work if enable_if removed
    //f(std::move(i));  // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘std::remove_reference<int&>::type {aka int}’
    //f(std::move(ci)); // error: no matching function for call to ‘f(std::remove_reference<const int&>::type)’... Will work if enable_if removed

    return 0;
}