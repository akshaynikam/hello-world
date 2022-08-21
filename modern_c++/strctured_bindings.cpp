// C++17

#include <iostream>
#include <cassert>

struct myStruct {
    int i = 0;
    std::string s;

    myStruct(int i, std::string s) : i(i), s(s) {}
    myStruct(const myStruct& ms) : i(ms.i), s(ms.s) {
        std::cout << "myStruct copy\n"; 
    }
};

int main() {
    myStruct ms {10, "Akshay"};

    std::cout << ms.i << " : " << ms.s << '\n';

    auto [i, s] = ms;
    /* It is equivalent to
    auto e = ms;    --> here copy constructor gets called
    aliasname i = e.i;
    aliasname s = e.s;
    */

    auto& [ri, rs] = ms;
    /* It is equivalent to
    auto& e = ms;
    aliasname i = e.i;
    aliasname s = e.s;
    */

    ms.i = 20;
    ms.s = "Patil";

    std::cout << i << " : " << s << '\n';
    std::cout << ri << " : " << rs << '\n';

    /*
        To the anonymous entity e the usual address and alignment guarantees apply,
        so that the structured bindings are aligned as the corresponding members they bind to.
        For example:
    */
    assert(&((myStruct*)&i)->s == &s); // OK!
    std::cout << &((myStruct*)&i)->s << " : " << &s << '\n';

    // Where structured bindings can be used:
    // Strctures with oublic data members,
    // raw C-style array and
    // tuple like objects
    int arr[] = {10, 20};

    auto [arr0, arr1] = arr;

    std::cout << arr0 << " : " << arr1 << "\n";

    return 0;
}