#include <iostream>

std::string get_str(int id) {
    std::string str[] = {
        "0 abc",
        "1 def",
        "2 hij",
        "3 klm"
    };

    return str[id];
}

template <typename T>
void fun_impl(T&& var, std::false_type) {
    std::cout << "fun_impl false_type: " << var << std::endl;
}

void fun_impl(int id, std::true_type);

template <typename T>
void fun(T&& var) {
    std::cout << "fun: " << var << std::endl;
    fun_impl(var, std::is_integral<std::remove_reference_t<T>>());
}

void fun_impl(int id, std::true_type) {
    std::cout << "fun_impl true_type: " << id << std::endl;
    fun(get_str(id));
}

int main() {
    fun(2.38);
    fun("Akshay");
    fun(0);

    return 0;
}