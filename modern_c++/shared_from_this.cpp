#include <iostream>
#include <memory>
#include <vector>

class demo;

auto process_demo = std::vector<std::shared_ptr<demo>>();

class demo : public std::enable_shared_from_this<demo> {    // This is "Curiously Recurring Template Pattern (CRTP)"
    public:
        demo() {std::cout << "demo()\n";}
        ~demo() {std::cout << "~demo()\n";}

        void process() {
            process_demo.emplace_back(shared_from_this());  // shared_from_this doesnt create new control block but looks for current object's control block
        }
};

int main() {
    auto d = std::shared_ptr<demo> (new demo()); // shared_from_this relies on this statement, otherwise it will crash

    d->process();

    return 0;
}