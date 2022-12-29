#include <iostream>
#include <string>

class boolString {
    std::string value;
    public:
        boolString(std::string const& str)
        : value(str) {
        }

        template<typename T = std::string>
        T get() const {
            return value;
        }
};

template<>
inline bool boolString::get<bool>() const {
    return value == "true" || value == "1" || value == "on";
}

int main() {
    boolString s1("Hello");
    std::cout << s1.get() << std::endl;
    std::cout << s1.get<bool>() << std::endl;
    boolString s2("on");
    std::cout << s2.get() << std::endl;
    std::cout << s2.get<bool>() << std::endl;

    return 0;
}