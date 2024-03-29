#include <iostream>
#include <vector>
#include <deque>
#include <memory>
#include <cassert>

template <typename T,
          template<typename Elem,
                   typename=std::allocator<Elem>>
          class Cont = std::deque>
class Stack {
    Cont<T> elems;

    public:
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const {
            return elems.empty();
        }

        template<typename T2,
                 template<typename Elem2,
                          typename = std::allocator<Elem2>
                          >class Cont2>
        Stack<T, Cont>& operator=(Stack<T2, Cont2> const&);

        template<typename, template<typename, typename> class>
        friend class Stack;
};

template <typename T, template<typename, typename> class Cont>
void Stack<T, Cont>::push(T const& elem) {
    elems.push_back(elem);
}

template <typename T, template<typename, typename> class Cont>
void Stack<T, Cont>::pop() {
    assert(!elems.empty());

    elems.pop_back();
}

template <typename T, template<typename, typename> class Cont>
T const& Stack<T, Cont>::top() const {
    assert(!elems.empty());

    return elems.back();
}

template<typename T, template<typename, typename> class Cont>
    template<typename T2, template<typename, typename> class Cont2>
Stack<T, Cont>&
Stack<T, Cont>::operator=(Stack<T2, Cont2> const& op2) {
    elems.clear();
    elems.insert(elems.begin(),
                 op2.elems.begin(),
                 op2.elems.end());
    
    return *this;
}

int main() {
    Stack<int>   iStack;
    Stack<float> fStack;

    // manipulate int stack
    iStack.push(1);
    iStack.push(2);
    std::cout << "iStack.top(): " << iStack.top() << std::endl;
    // manipulate float stack:
    fStack.push(3.3);
    std::cout << "fStack.top(): " << fStack.top() << std::endl;
    // assign stack of different type and manipulate again
    fStack = iStack;
    fStack.push(4.4);
    std::cout << "fStack.top(): " << fStack.top() << std::endl;
    // stack for doubless using a vector as an internal container
    Stack<double, std::vector> vStack; vStack.push(5.5);
    vStack.push(6.6);
    std::cout << "vStack.top(): " << vStack.top() << std::endl;
    vStack = fStack;
    std::cout << "vStack: ";
    while (! vStack.empty()) {
        std::cout << vStack.top() << std::endl;
        vStack.pop();
    }

    std::cout << std::endl;

    return 0;
}