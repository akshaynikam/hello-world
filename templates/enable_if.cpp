#include <iostream>
#include <string>

class demo {
    std::string name;
    public:
        template<typename STR,
                 typename = std::enable_if_t<std::is_convertible_v<STR, std::string>>>
        explicit demo(STR&& n) : name(std::forward<STR>(n)) {
            std::cout << "TMPL-CONSTR for " << name << std::endl;
        }

        demo(demo&& d) : name(std::move(d.name)) {
            std::cout << "MOVE-CONSTR demo " << name << std::endl;
        }

        demo(demo const& d) : name(d.name) {
            std::cout << "COPY-COSTR demo " << name << std::endl;
        }
};

int main() {
    std::string s = "sname";

    demo d1(s);
    demo d2("tmp");

    demo d3(d2); // error without enable_if, becuase it template constructor is better match here that copy constructor
    demo d4(std::move(d1));

    return 0;
}