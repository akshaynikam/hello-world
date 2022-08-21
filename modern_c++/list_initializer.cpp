#include <iostream>
#include <initializer_list>

class demo {
	int i;
public:
	demo() {
		std::cout << "demo()\n";
	}

	demo(int i) {
		std::cout << "demo(" << i << ")\n";
	}

	demo(std::initializer_list<int> d) {
		std::cout << "demo(std::initializer_list)\n";
	}
};

int main() {
	demo d1(10); // call demo constructor with argument 10
	demo d2();	 // most vesting parse! declares a function named d2 that returns demo!
	demo d3{};	 // call demo constructor with no arguments

	double i{3};
	//int i{3.0};	// error: requires narrowing conversions. double cannot be converted to int

	return 0;
}
