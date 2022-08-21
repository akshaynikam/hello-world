// constexpr objects are const and are initialized with values known during compilation.
// constexpr functions can produce compile-time results when called with arguments whose values are known during compilation.
// constexpr objects and functions may be used in a wider range of contexts than non-constexpr objects and functions.
// constexpr is a part of an object's or function's interface.

#include <iostream>

class point {
    double x;
    double y;

    public:
        constexpr point(double xV = 0, double yV = 0) noexcept : x(xV), y(yV) {}
        constexpr double xValue() const noexcept { return x; }
        constexpr double yValue() const noexcept { return y; }
        constexpr void setX(double newX) noexcept { x = newX; } // not allowed to be constexpr in C++11 since it modifies the object they operate on and
        constexpr void setY(double newY) noexcept { y = newY; } // in C++ constexpr member functions are implicitly const.  Allowed in C++14
};

constexpr point midpoint(const point& p1, const point& p2) noexcept {
    return { (p1.xValue() + p2.xValue()) / 2,
             (p1.yValue() + p2.yValue()) / 2 };
}

int main() {
    constexpr point p1(9.4, 27.7);
    constexpr point p2(28.8, 5.3);

    std::cout << "P1 -> (" << p1.xValue() << ", " << p1.yValue() << ")\n";
    std::cout << "P2 -> (" << p2.xValue() << ", " << p2.yValue() << ")\n";

    constexpr auto mid = midpoint(p1, p2);

    std::cout << "Mid -> (" << mid.xValue() << ", " << mid.yValue() << ")\n";

    return 0;
}