#include <iostream>
#include <cstdalign>

struct alignas(16) sse_t {
    char buff[5];
};

int main() {
    sse_t arr[2];

    std::cout << &arr[0] << " : " << &arr[1] << '\n';

    return 0;
}