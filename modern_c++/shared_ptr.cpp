#include <iostream>
#include <memory>

class demo {
    public:
        demo() {std::cout << "demo()\n";}
        ~demo() {std::cout << "~demo()\n";}
};

int main() {
    auto sp1 = std::make_shared<demo>(); // creates control block which keeps track of reference count
    auto sp2 = sp1;                                // sp1 & sp2 points to same control block
    auto up = std::unique_ptr<demo> (new demo());  // wont create control block since its unique_ptr
    auto sp3 = std::shared_ptr<demo> (std::move(up));   // creates control block since creating shared_ptr from unique_ptr
    auto d = new demo();
    auto sp4 = std::shared_ptr<demo> (d);
    auto sp5 = std::shared_ptr<demo> (d);

    return 0;
}