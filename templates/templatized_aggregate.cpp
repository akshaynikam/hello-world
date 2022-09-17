#include <iostream>
#include <string>

template <typename T>
struct valueWithComment {
    T value;
    std::string comment;
};

// -> deduction guide
valueWithComment(const char*, const char*) -> valueWithComment<std::string>;

int main() {
    valueWithComment<int> ivc = {10, "Initial value"};

    std::cout << ivc.value << " : " << ivc.comment << std::endl;

    valueWithComment svc = {"Akshay", "My Name"};

    std::cout << svc.value << " : " << svc.comment << std::endl;

    return 0;
}