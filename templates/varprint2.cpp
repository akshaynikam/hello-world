#include <iostream>

template <typename T>
void print(T x) {
    std::cout << x << std::endl;
}

template <typename T, typename... Types>
void print(T firstArg, Types... args) {
    print(firstArg);    // call print for first argument
    print(args...);     // call print for remaining arguments
}

int main() {
    print(15u, "Akshay", 3.14);

    return 0;
}