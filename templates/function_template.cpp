#include <iostream>
#include <string>

template <typename T>
T max(T a, T b) {
    return b < a ? a : b;
}

int main() {
    std::cout << ::max(5, 6) << std::endl;
    std::cout << ::max(std::string("akshay"), std::string("nikam")) << std::endl;

    return 0;
}