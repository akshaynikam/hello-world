#include <iostream>
#include <utility>
#include <functional>
#include <array>

template<typename Iter, typename Callable, typename... Args>
void foreach(Iter current, Iter end, Callable op, Args const&... arg) {
    while (current != end) {
        std::invoke(op, arg..., *current);
        current++;
    }
}

class demo {
    public:
        void fun(int i) const {
            std::cout << i * 10 << " ";
        }
};

int main() {
    std::array<int, 5> arr {11, 22, 33, 44, 55};

    foreach(arr.begin(), arr.end(), [](int i) { std::cout << i << " "; });
    std::cout << std::endl;

    demo d;

    foreach(arr.begin(), arr.end(), &demo::fun, d);
    std::cout << std::endl;

    return 0;
}