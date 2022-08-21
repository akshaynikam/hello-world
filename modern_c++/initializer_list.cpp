#include <iostream>
#include <vector>
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

	operator int() const {return 0;}
};

int main() {
	demo d1(10); // calls demo constructor with argument 10
	demo d2();	 // most vesting parse! declares a function named d2 that returns demo!
	demo d3{};	 // calls demo constructor with no arguments.
				 // empty braces means no arguments, not an empty std::initializer_list.

	double i{3}; // does implicit conversion from int to double
	//int i{3.0};	// error: requires narrowing conversions. double cannot be converted to int
	
	demo d4(d3); // calls demo copy constructor
	demo d5(std::move(d4));	// call demo move constructor

	demo d6{d1};	// calls std::initializer_list constructor if implicit conversion function is provided (operator int() const)
	demo d7{std::move(d1)};	// calls std::initializer_list constructor if implicit conversion function is provided (operator int() const)

	demo d8{8}; // calls std::initializer_list constructor.
	demo d9({}); // calls std::initializer_list constructor with empty list


	// std::vector has a non-std::initializer_list constructor that allows you to
	// specify the initial size of the container and a value each of the elements should have
	// but it also has a std::initializer_list constructor that permits you to specify the initial values in the container.
	
	std::vector<int> v1(5, 2); // use non-std::initializer_list constructor: create 5 elements all having value of 2
	std::vector<int> v2{5, 2}; // use std::initializer_list constructor: create 2 elements of value 5 and 2

	std::cout << "v1 : ";
	for (auto e : v1)
		std::cout << e << " ";
	std::cout << "\nv2 : ";
	for (auto e : v2)
		std::cout << e << " ";

	std::cout << std::endl;

	return 0;
}
