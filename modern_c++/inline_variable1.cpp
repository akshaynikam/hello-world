#include <iostream>
#include "inline_variable.h"

void fun();

int main() {
    std::cout << "INLINE CPP 1: " << demo::var << '\n';

    demo::var = 20;

    fun();

    return 0;
}