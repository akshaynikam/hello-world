#include <iostream>
#include <memory>

int f1(std::shared_ptr<int> sp) {
    std::cout << "f1\n";
    return 0;
}

template <typename funType,
          typename argType>
decltype(auto) call(funType fun, argType arg) {
    return fun(arg);
}

int main() {
    f1(0);
    f1(nullptr);
    //call(f1, 0);      error: could not convert ‘arg’ from ‘int’ to ‘std::shared_ptr<int>’.. template tyep deduction comes into play and deducts type of 0 as int
    call(f1, nullptr);

    return 0;
}