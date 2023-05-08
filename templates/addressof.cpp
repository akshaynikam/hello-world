#include <iostream>

class demo {
    public:
        void operator&() {
            std::cout << "Inside custome &\n";
        }
};

int main() {
    demo d;
    &d;

    //auto addr = &d;   // error: ‘void addr’ has incomplete type
    auto addr = std::addressof(d);

    std::cout << addr << std::endl;

    return 0;
}