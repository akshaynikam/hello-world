#include <iostream>
#include <array>

// In C++11,  perhaps the primary use of decltype is declaring function templates
// where function's return type is depende on its parameter types.

template <typename Container, typename Index>
auto get_11(Container& c, Index i) -> decltype(c[i]) {
	return c[i];
}

// In C++14, we can omit the trailing return type. leaving just the leading auto.
template <typename Container, typename Index>
decltype(auto) get_14(Container& c, Index i) {
	return c[i];
}

// Employ a reference parameter hat can bind lavlues and rvalues
template<typename Container, typename Index>
decltype(auto) get_14_uref(Container&& c, Index i) {
	return c[i];
}

// Final C++14 version
template<typename Container, typename Index>
decltype(auto) get_final_14(Container&& c, Index i) {
	return std::forward<Container>(c)[i];
}

// For lvalue expressions of type T other than names, decltype always reports a type of T&
decltype(auto) f1() {
	int x = 0;
	return x; // decltype(x) is int, so f1 returns int
}

decltype(auto) f2() {
	int x = 0;
	return (x); // decltype((x)) is int&, so f2 returns int&
}

int main() {
	std::array<int, 3> ai {1, 2, 3};
	std::array<char, 3> ac {'a', 'b', 'c'};

	get_14(ac, 1) = 'z';

	std::cout << get_11(ai, 1) << std::endl;
	std::cout << get_14(ac, 1) << std::endl;

	// The use of decltype(auto) is not limited to function return types.
	// It can also be convenient for declaring variables when you want to apply
	// the decltype deduction rules to the initializing expession:
	int i = 27; 			// i is int
	const int& ci = i;		// ci is of type const int&
	auto aci = ci;			// auto type deduction:
							// aci is of type int
	decltype(auto) dci = i;	// decltype type deduction:
							// dci is of type const int&
	
	// But still we cannot pass rvalue container to get_14 function
	// because its argument is non const lavlue reference which we cannot bind to rvalue object
	/*
	get_14(std::array<int, 3>({1, 2, 3}), 2); // error: cannot bind non-const lvalue reference
	*/
	

	// A way to avoid this is to have get_14 employ a reference parameter that can bind lvalues and rvalues.
	get_14_uref(std::array<int, 3>({1, 2, 3}), 2);

	// But in this case we dont know what type of container we are opering on
	// So use std::forward<>
	get_final_14(std::array<int, 3>({1, 2, 3}), 2);

	// Applying decltype to a name yields the declared type for that name.
	// Names are typically lvalue expressions.
	// For lvalue expressions more complecated than names, however decltype generally ensures that type reported is an lvalue reference.
	/*
	f1() = 10; // error: because f1 returns rvalue while f2 will return lvalue reference
	f2() = 10; // works but should not use like this as f2() will return reference to local variable which will lead to undefined behaviour
	*/

	return 0;
}
