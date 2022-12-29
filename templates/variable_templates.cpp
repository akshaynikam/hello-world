#include <iostream>

template<typename T = long double>
constexpr T pi {3.1415926535897932385};

int main() {
    std::cout << pi<double> << std::endl;
    std::cout << pi<float> << std::endl;
    std::cout << pi<> << std::endl;

    return 0;
}