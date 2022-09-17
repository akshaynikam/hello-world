#include <iostream>

template <auto T>
class Message {
    public:
        void print() {
            std::cout << T << '\n';
        }
};

int main() {
    Message<5> intMsg;
    // Message<3.14> dblMsg;    // ERROR: Floating-point nontype argument
    static const char msg[] = "Akshay";
    Message<msg> strMsg;

    intMsg.print();
    strMsg.print();

    return 0;
}