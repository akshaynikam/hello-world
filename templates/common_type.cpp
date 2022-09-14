#include <iostream>
#include <type_traits>

template <typename T1, typename T2>
std::common_type_t<T1, T2> max1(T1 a, T2 b) {
    return b < a ? a : b;
}

template <typename T1, typename T2,
          typename RT = std::common_type_t<T1, T2>>
RT max2(T1 a, T2 b) {
    return b < a ? a : b;
}

int main() {
    std::cout << ::max1(4, 5.5) << std::endl;
    std::cout << ::max2(5.5, 4) << std::endl;

    return 0;
}