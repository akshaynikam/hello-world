#include <iostream>

int main() {
	auto i = 10;  // must to have initializer
	int ci = 20;

	auto a = &ci;
	auto *p = &ci;

	std::cout << *a << " : " << *p << std::endl;

	return 0;
}
