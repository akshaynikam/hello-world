#include <iostream>
#include <cstdint>
#include <string>
#include <tuple>


using UserInfo = std::tuple<std::string, std::string, std::size_t> ;

enum class UserInfoFields {uiName, uiEmail, uiReputation};

template<typename E>
constexpr auto toUType(E enumerator) noexcept {
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

int main() {
    UserInfo ui = std::make_tuple("Akshay", "aknikam@gmail.com", 100);

    std::cout << std::get<0>(ui) << std::endl;
    std::cout << std::get<static_cast<std::size_t>(UserInfoFields::uiEmail)>(ui) << std::endl;
    std::cout << std::get<toUType(UserInfoFields::uiReputation)>(ui) << std::endl;

    return 0;
}