#include <iostream>
#include <map>

int main() {
    std::map <int, std::string> m;

    auto [pos1, ok1] = m.insert({1, "Akshay"});

    std::cout << pos1->first << " : " << ok1 << std::endl;

    if (auto [pos, ok] = m.insert({1, "Nikam"}); !ok) {
        auto [key, val] = *pos;

        std::cout << key << " already exists with " << val << std::endl;
    }

    return 0;
}