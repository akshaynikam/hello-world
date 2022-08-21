#include <iostream>

class demo {
    public:
        static const int min = 28;
};

void fun(const int& min) {
    std::cout << "fun(min): " << min << std::endl;
}

int main() {
    std::cout << "static const int min: " << demo::min << std::endl;

    fun(demo::min);

    return 0;
}