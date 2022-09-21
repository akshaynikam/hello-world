#include <iostream>

// this approach doesn’t work because in general both branches of all if statements in function templates are instantiated.
// Whether the instantiated code is useful is a run-time decision, while the instantiation of the call is a compile-time decision.

template <typename T, typename... Types>
void print(T firstArg, Types... args) {
    std::cout << firstArg << std::endl;
    if (sizeof...(args) > 0)
        print(args...);
}

int main() {
    print(25u, "Akshay", 3.14);

    return 0;
}