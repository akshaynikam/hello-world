#include <iostream>

void print() {
    std::cout << std::endl;
}

template <typename T, typename... Types>
void print(T param, Types... args) {
    std::cout << param << " ";
    print(args...);
}

int main() {
    print(10u, "Akshay", 3.14);

    return 0;
}