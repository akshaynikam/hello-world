#include <iostream>
#include <vector>

// auto type deduction works exactly same as template type deductions.
// Case 1: The type specifier is a pointer or reference.
// Case 2: The type specifier is a universal reference.
// Case 3: The type specifier is neither a pointer or reference.

void func(int i, double d) { // func type is void (int, double)
	;
}

template<typename T>
void f1(T param) {
	;
}

template<typename T>
void f2(std::initializer_list<T> param) {
	;
}


int main() {
	auto x = 27;		// case 3 (x is neither ptr nor ref)
	const auto cx = x;	// case 3 (cx isn't either)
	const auto& rx = x;	// case 1 (rx is a non-universal ref)

	// case 2works as you'd expect:
	auto&& uref1 = x;	// x is int and lvalue,
						// so uref1's type is int&
	auto&& uref2 = cx;	// cx is const int and lvalue,
						// so uref2's type is const int&
	auto&& uref3 = 27;	// 27 is int and rvalue,
						// so uref3's type is int&&

	// Array and functions type specifiers
	const char name[] = "Akshay Nikam";	// name's type is const char[13]
	auto arr1 = name;	// arr1 is const char*
	auto& arr2 = name;	// arr2 is const char (&)[13]

	auto func1 = func;	// func1 is void (*)(int, double)
	auto& func2 = func; // func2 is void (&)(int, double)

	// Only exception for auto type deductions:
	// int x1 = 27;
	// int x2(27);
	// int x3 = {27};
	// int x4{27};
	// All above statements means an int with value 27
	auto x1 = 27;		// type is int, value is 27
	auto x2(27);		// type is int, value is 27
	auto x3 = {27};		// type is std::initializer_list<int>, value is {27}
	auto x4{27};		// type is std::initializer_list<int>, value is {27}

	//f1({1, 2, 3});	// error: can't deduce type for T
	f2({1, 2, 3});		// T deduced as int, and
						// param's type is std::initializer_list<int>

	// So the only real difference between auto and template type deduction is that auto assumes that
	// a braced initializer represents a std::initializer_list, but template type deduction doesn't

	// C++14
	// C++14 permits auto to indicate that a functions return type should be deduced and
	// C++14 lambdas may use auto in parameter declarations. However these use of auto employ
	// template type deduction, not auto type deduction.

	/*
	auto createInitLis() {
		return {1, 2, 3};	// error: can't deduce type for {1, 2, 3}
	}
	*/

	// same is true when auto is used in parameter type specification in c++14 labda:
	std::vector<int> v;
	auto resetV = [&v](const auto& newValue) {v = newValue;}; // C++14

	/*
	resetV({1, 2, 3});		// error: can't deduce type for {1, 2, 3}
	*/

	return 0;
}

