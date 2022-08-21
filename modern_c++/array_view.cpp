#include <iostream>
#include <vector>
#include <ranges>

template <typename T>
void print(const T& coll) {
    for (const auto& elem : coll) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::vector<int> vec{1, 2, 3, 4, 5};

    print(vec | std::views::drop(3));

    return 0;
}