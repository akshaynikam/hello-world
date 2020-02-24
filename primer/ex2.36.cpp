#include <iostream>

int main() {
	int a = 3, b = 4;
	decltype(a) c = a;// c is int with initial value 3
	decltype((b)) d = a;// d is int reference for a with initial value 3

	++c; // c = 4
	++d; // d = a = 4

	std::cout << "a : " << a << std::endl; //a : 4  
	std::cout << "b : " << b << std::endl; //b : 4
	std::cout << "c : " << c << std::endl; //c : 4
	std::cout << "d : " << d << std::endl; //d : 4

	return 0;
}
