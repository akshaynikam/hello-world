#include <iostream>

class base {
    public:
        virtual void f1() const {}
        virtual void f2(int i) {}
        virtual void f3(int i) & {}
};

class devireved : public base {
    public:
        void f1() const override {} // const should be present
        void f2(int) override {}    // arguments should be of same type
        void f3(int i) & override {} // reference qualification should be same
};

int main() {
    return 0;
}