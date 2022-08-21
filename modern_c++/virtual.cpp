#include <iostream>

class base {
    public:
        int i;
        int* pi;

        base() {
            i = 10;
            pi = new int();
            *pi = 20;
        }

        //~base() {
        //    if (pi != nullptr)
        //        delete pi;
        //}

        //base(base&& b) {
        //    i = b.i;
        //    pi = b.pi;
        //    b.pi = nullptr;
        //}
};

int main() {
    base b1;

    std::cout << b1.i << " : " << *(b1.pi) << std::endl;

    std::cout << &b1 << std::endl;

    base b2 = std::move(b1);

    std::cout << b2.i << " : " << *(b2.pi) << std::endl;
    std::cout << b1.i << " : " << *(b1.pi) << std::endl;

    std::cout << &b1 << " : " << &b2 << std::endl;

    return 0;
}