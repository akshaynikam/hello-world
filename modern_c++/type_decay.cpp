// std::decay removes const and volatile qualifiers

#include <iostream>

class base {
    public:
        base() {}
        ~base() {}
        base(const base& b) {
            std::cout << "base(const base&)\n";
        }

        // template <typename T, typename = typename std::enable_if<!std::is_base_of<base, typename std::decay<T>::type>::value>::type> //  C++11
        template <typename T, typename = std::enable_if_t<!std::is_base_of<base, std::decay_t<T>>::value>>                              //  C++14
        base(T&& var) {
            std::cout << "base(T&&)\n";
        }
};

class demo : public base {
    public:
        demo() {}
        ~demo() {}
        demo(const demo& d) : base(d) {
            std::cout << "demo(const demo&)\n";
        }
        
        //template <typename T, typename = typename std::enable_if<!std::is_same<demo, typename std::decay<T>::type>::value>::type> //  C++11
        template <typename T, typename = std::enable_if_t<!std::is_same<demo, std::decay_t<T>>::value>>                             //  C++14
        demo(T&& var) {
            std::cout << "demo(T&&)\n";
        }
};

int main() {
    demo d1;

    demo d2(0);

    demo d3(d2);    // calls universal reference constructor without decay
                    // calls copy constructor with decay
                    // calls universal reference constructor for base class without is_base_of trait
                    // calls base class copy constructor with is_base_of trait

    const demo d4;
    demo d5(d4);    // calls copy constructor

    return 0;
}