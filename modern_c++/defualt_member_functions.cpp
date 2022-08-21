// compiler generates default move constructor and move assignment only if user doesnt provide copy, assignment and destructor
// In such case move operation becomes copy
// In compiler generated default copy/move functions does member wise copy/move operation

#include <iostream>

class resource {
    public:
        resource() = default;
        ~resource() = default;

        resource(const resource& r) { std::cout << "resource copy\n"; }
        resource(resource&& r) { std::cout << "resource move\n"; }
};

class demo {
    resource r;
    public:
        demo() = default;
        ~demo() = default;
        demo(const demo&) {std::cout << "demo copy\n";}
        demo& operator=(const demo&) = default;
        demo(demo&&) = default;
        demo& operator=(demo&&) = default;
};


int main() {
    demo d1;
    demo d2(d1);
    demo d3(std::move(d1));

    return 0;
}