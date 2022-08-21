#include <iostream>

class demo {
	int i;
public:
	demo() {
		std::cout << "demo()\n";
	}

	demo(int i) {
		std::cout << "demo(" << i << ")\n";
	}

	void fun() {}
};

int main() {
	demo d1(10); // call demo constructor with argument 10
	demo d2();	 // most vesting parse! declares a function named d2 that returns demo!

	d2.fun();
	demo d3{};	 // call demo constructor with no arguments

	//int i{3.0};

	return 0;
}
