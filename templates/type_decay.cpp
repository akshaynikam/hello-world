#include <iostream>

template<typename T, std::size_t L1, std::size_t L2>
void f1(T (&arg1)[L1], T (&arg2)[L2]) {
    std::cout << sizeof(arg1) << " : " << sizeof(arg2) << "\n";
}

template<typename T>
void f2(T& arg1, T& arg2) {
    std::cout << sizeof(arg1) << " : " << sizeof(arg2) << "\n";
}

template<typename T>
void f3(T arg1, T arg2) {
    std::cout << sizeof(arg1) << " : " << sizeof(arg2) << "\n";
}

int main() {
    f1("hi", "bye");
    //f2("hi", "bye");  // error: no matching function for call to ‘f(const char [3], const char [4])’
    f3("hi", "bye");    // compiles, but type decays and T deduced as a pointer

    return 0;
}