#include <iostream>

template <typename T = std::string>
void fun(T p = "Patil") {
    std::cout << p << std::endl;
}

int main() {
    fun(23);
    fun("Akshay");
    fun();

    return 0;
}