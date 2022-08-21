#include <iostream>
#include <string>

void process(const int& i) {
    std::cout << "process (const int&)\n";
}

void process(int&& i) {
    std::cout << "processs (int&&)\n";
}

template <typename T>
void call(T&& i) {
    process(std::forward<T>(i));    //Forward conditionally casts the parameter into rvalue if its intialized with rvalue.
}

int main() {
    int i = 0;
    call(i);
    call(std::move(i));
}