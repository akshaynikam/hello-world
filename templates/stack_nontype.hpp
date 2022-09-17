#include <array>
#include <cassert>

template <typename T, std::size_t MaxSize>
class Stack {
    private:
        std::array<T, MaxSize> elems;
        std::size_t numElems;
    public:
        Stack();
        void push(T const& elem);
        void pop();
        T const& top() const;
        bool empty() const {
            return numElems == 0;
        }
        std::size_t size() const {
            return numElems;
        }
};

template <typename T, std::size_t MaxSize>
Stack<T, MaxSize>::Stack() : numElems(0) {}

template <typename T, std::size_t MaxSize>
void Stack<T, MaxSize>::push(T const& elem) {
    assert(numElems < MaxSize);
    elems[numElems] = elem;
    ++numElems;
}

template <typename T, std::size_t MaxSize>
void Stack<T, MaxSize>::pop() {
    assert(!empty());
    --numElems;
}

template <typename T, std::size_t MaxSize>
T const& Stack<T, MaxSize>::top() const {
    assert(!empty());
    return elems[numElems - 1];
}