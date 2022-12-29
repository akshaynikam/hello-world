#include <iostream>

// If T is built in type then there is no default constructor which initializes them with a usefull value
template <typename T>
class demo {
    // This way of initialization is called value initialization, which means to either call a provided constructor or zero initialize an object.
    T x{};  // initializes to 0
    T y;    // not initializes (garbage)
    public:
        void print() {
            std::cout << x << std::endl;    // prints 0
            std::cout << y << std::endl;    // prints garbage
        }
};

int main() {
    demo<int> i;

    i.print();

    return 0;
}