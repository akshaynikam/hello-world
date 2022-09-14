#include <iostream>

template <typename T>
void fun(T a, T b) {
    std::cout << "fun<>\n";
}

void fun(int i, int j) {
    std::cout << "fun(int, int)\n";
}

int main() {
    fun(1, 2);      //fun(int, int)
    fun('a', 'b');  //fun<>
    fun(4.5, 4.5);  //fun<>
    fun(1, 2.1);    //fun(int, int)
    fun('a', 2);    //fun(int, int)
    fun<>(2, 2);    //fun<>

    return 0;
}