#include <iostream>
#include <functional>

class demo {
    public:
        demo() {}
        demo(const demo& d) { std::cout << "demo(const demo&)\n"; }
        demo(demo&& d) { std::cout << "demo(demo&&)\n"; }
};

int main() {
    demo d;
    std::cout << "Before bind\n";
    auto fun = std::bind([](const demo& d) { std::cout << "from lambda " << std::endl;}, std::move(d));
    std::cout << "After bind\n";
    fun();

    return 0;
}