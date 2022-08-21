// RVO - Return Value Optimization
// 

#include <iostream>

class data {
    public:
        data() {std::cout << "data()\n";}
        ~data() {std::cout << "~data()\n";}
        data(const data& d) {std::cout << "data(const data&)\n";}
        data(data&& d) {std::cout << "data(data&&)\n";}
};

// If conditions for the RVO are met, but compilers choose not to perform copy elision, the objects being returned must be treated as an rvalue.
data fun(data d1) {
    return d1;  // This will be treated as std::move(d1)
}

// RVO can avoid copy the local variable by contructing it in the memory alloted for the function's return value
data fun() {
    data d; // This will be constructed in memory alloated for function's return value

    return d;
}

int main() {
    data d;

    data d2 = fun(d);

    data d3 = fun();

    return 0;
}