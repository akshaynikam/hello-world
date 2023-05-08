#include <functional>
#include <iostream>

template<typename Callable, typename... Args>
decltype(auto) call(Callable op, Args&&... args) {
    if constexpr(std::is_same_v<std::invoke_result_t<Callable, Args...>, void>) {
        // return type is void
        std::invoke(op, args...);
        return;
    } else {
        // return type is not void
        decltype(auto) ret { std::invoke(op, args...) };
        return ret;
    }
}

int main() {
    call([](int i) { return i * 10; }, 10);
    call([](int i) { std::cout << i << "\n";}, 100);

    return 0;
}