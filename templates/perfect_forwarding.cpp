#include <iostream>

void f(int& i) {
    std::cout << "f(int&)\n";
}

void f(const int& i) {
    std::cout << "f(const int&)\n";
}

void f(int&& i) {
    std::cout << "f(int&&)\n";
}

template<typename T>
void g(T&& i) {
    f(std::forward<T>(i));
}

int main() {
    int i = 10;
    const int c = 20;

    g(i);
    g(c);
    g(std::move(i));

    return 0;
}