#include <iostream>
#include <memory>

class demo {
    public:
        demo() { std::cout << "demo()\n"; }
        ~demo() { std::cout << "~demo()\n"; }
};

int main() {
    auto custom_del = [](demo* ptr) {
        std::cout << "From custom deleter\n";
        delete ptr;
    };

    auto up = std::unique_ptr<demo, decltype(custom_del)> (nullptr, custom_del);
    //std::unique_ptr<demo> d (new demo());

    up.reset(new demo());

    auto sp = std::shared_ptr<demo> (std::move(up));

    //auto d1 = d; error: use of deleted function ‘std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&)

    //std::unique_ptr<demo[]> d_arr(new demo[5]);

    return 0;
}