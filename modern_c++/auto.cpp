#include <iostream>
#include <string>
#include <unordered_map>

void fun(auto i, auto j) {
	;
}

int main() {
	fun(0, 1);

	std::unordered_map<std::string, int> m;
	m["a"] = 1;
	m["b"] = 2;

	std::cout << "&m[\"a\"] : " << &m["a"] << std::endl;
	std::cout << "&m[\"b\"] : " << &m["b"] << std::endl;

	for (const std::pair<std::string, int>& p : m) {
		std::cout << "&p : " << &p << std::endl;
	}

	for (auto& p : m) {
		std::cout << "&p : " << &p << std::endl;
	}

	for (auto i : m)
		std::cout << i.first << " : " << i.second << std::endl;

	return 0;
}
