#include <algorithm>
#include <iostream>
#include <vector>

template <int val, typename T>
T addValue(T arg) {
    return arg + val;
}

int main() {
    std::vector<int> src {10, 20, 30};
    std::vector<int> dst(3);

    for (auto i : src)
        std::cout << i << " ";
    std::cout << std::endl;

    std::transform(src.begin(), src.end(), dst.begin(), addValue<5, int>);

    std::cout << std::endl;
    for (auto i : dst)
        std::cout << i << " ";
    std::cout << std::endl;

    std::transform(dst.begin(), dst.end(), dst.begin(), [](int i) { return i*2; });

    std::cout << std::endl;
    for (auto i : dst)
        std::cout << i << " ";
    std::cout << std::endl;

    return 0;
}