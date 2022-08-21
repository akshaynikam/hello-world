// Use std::weak_ptr for std::shared_ptr like pointers that can dangle.
// Potential use cases for std::weak_ptr  include caching, observer lists, and the prevention of std::shared_ptr cycles.

#include <iostream>
#include <memory>

class data {
    public:
        data() {std::cout << "data()\n";}
        ~data() {std::cout << "~data()\n";}
};

int main() {
    auto sp = std::make_shared<data>();
    auto wp = std::weak_ptr<data>(sp);

    sp = nullptr;

    if (wp.expired()) {
        std::cout << "shared_ptr expired\n";
    }

    //std::shared_ptr<data> sp1(wp);    // throws exception: bad_weak_ptr if pointer dangles
    auto np = wp.lock();

    if (np) {
        std::cout << "np not null\n";
    } else {
        std::cout << "np null\n";
    }

    std::cout << "Exiting\n";
    return 0;
}