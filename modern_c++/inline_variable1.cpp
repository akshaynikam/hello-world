#include <iostream>
#include "inline_variable.h"

void fun();

int main() {
    std::cout << "INLINE CPP 1: " << demo::var << '\n';
    std::cout << "INLINE CPP 1: " << demo::name << '\n';

    demo::var = 20;

    fun();

    return 0;
}