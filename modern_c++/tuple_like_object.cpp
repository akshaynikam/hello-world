#include <iostream>
#include <utility>

class demo {
    private:
        std::string first;
        std::string last;
        long val;
    public:
        demo (const std::string& f, const std::string& l, const long& v) :
            first(f), last(l), val(v) {}
        
        std::string getFirst() const {return first;}
        std::string getLast() const {return last;}
        long getValue() const {return val;}
};

template<>
struct std::tuple_size<demo> {
    static constexpr int value = 3;
};

template<>
struct std::tuple_element<2, demo> {
    using type = long;
};

template<std::size_t Idx>
struct std::tuple_element<Idx, demo> {
    using type = std::string;
};

template<std::size_t> auto get (const demo& d);
template<> auto get<0> (const demo& d) {return d.getFirst();}
template<> auto get<1> (const demo& d) {return d.getLast();}
template<> auto get<2> (const demo& d) {return d.getValue();}

int main() {
    demo d {"Akshay", "Nikam", 100};

    std::cout << d.getFirst() << " : " << d.getLast() << " : " << d.getValue() << '\n';

    auto [first, last, val] = d;

    std::cout << first << " : " << last << " : " << val << '\n';

    return 0;
}