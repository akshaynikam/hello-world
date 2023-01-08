#include <iostream>
#include <functional>

template<typename T>
void f(T arg) {
    std::cout << sizeof(arg) << std::endl;
}

int main() {
    int arr[100] = {0};
    f(arr);
    f(std::ref(arr));
    f(std::cref(arr));

    return 0;
}