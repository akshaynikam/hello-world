#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <exception>


class log {
    private:
        unsigned N;
        std::deque<std::string> data;
    public:
        log(unsigned n) : N(n) {}
        void record(const std::string&);
        std::vector<std::string> get_last(unsigned i);
};

void log::record(const std::string& id) {
    data.push_back(id);
    if (data.size() >= N) {
        data.pop_front();
    }
}

std::vector<std::string> log::get_last(unsigned i) {
    if (i > N) {
        std::__throw_out_of_range("i greater than N");
    }

    std::vector<std::string> result;
    for (auto it = data.begin() + N - i - 1; it != data.end(); it++) {
        result.push_back(*it);
    }

    return result;
}

int main() {
    log l(5);

    l.record("1x");
    l.record("2x");
    l.record("3x");
    l.record("4x");
    l.record("5x");

    for (auto it : l.get_last(5)) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    l.record("6x");
    l.record("7x");

    for (auto it : l.get_last(3)) {
        std::cout << it << " ";
    }
    std::cout << std::endl;

    try {
        l.get_last(6);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;

}