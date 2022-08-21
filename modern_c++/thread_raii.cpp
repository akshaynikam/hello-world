#include <iostream>
#include <functional>
#include <thread>
#include <unistd.h>

// make thread unjoinable from all the paths

class thread_raii {
    public:
        enum class dtor_action {join, detach};
        thread_raii(std::thread&& t, dtor_action a) : action(a), t(std::move(t)) {}
        ~thread_raii() {
            if (t.joinable()) {
                if (action == dtor_action::join) {
                    t.join();
                } else {
                    t.detach();
                }
            }
        }

        std::thread& get() { return t; }

    private:
        dtor_action action;
        std::thread t;
};

class demo {
    public:
        void log() {
            std::cout << "demo::log()\n";
        }
};

bool condition = false;

bool do_work(std::function<bool(int)> fun, demo d) {
    thread_raii t(std::thread([&fun, &d]
                {
                    for (auto i = 0; i < 5; i++) {
                        if (fun(i)) {
                            sleep(2);
                            d.log();
                        }
                    }
                }),
                thread_raii::dtor_action::join);
    
    if (condition) {
        t.get().join();
        return true;
    }

    return false;
}

bool filter(int i) {
    return ((i % 2) == 0)? true : false;
}

int main() {
    do_work(filter, demo());

    return 0;
}