#include <iostream>

template<typename T>
void fun(T* t) {
    std::cout << "template instantiation\n";
}

template<>
void fun<void>(void*) = delete;

int main() {
    auto pi = (int *) nullptr;
    auto pv = (void *) nullptr;

    fun(pi);
    //fun(pv);  error: use of deleted function ‘void fun(T*) [with T = void]’

    return 0;
}