#include <iostream>
#include <array>

// Case 1: ParamType is pointer or reference but not universal reference.
// If param is reference then ingore the argument's reference part in type deduction
// If param is const then ignore the argument's constness in type deduction
template<typename T>
void f_ref(T& param) { // param is a reference
	;
}

template<typename T>
void f_const_ref(const T& param) { // param is a reference to const
	;
}

template<typename T>
void f_pointer(T* param) { // param is a pointer
	;
}


// Case 2: ParamType is is a Universal Reference
// If argument is an lvalue, both T and ParamType are deduced to be lvalue references.
// If argument is an rvalue, then "normal" (i.e Case1) rules apply.
template <typename T>
void f_ref_ref(T&& param) { // param is universal reference
	;
}

// Case 3: ParamType is neither a Pointer nor a Reference
// If argument's type is a reference, ignore the reference part.
// If after ignoring argument's reference-ness, argument is const, ignore that too.
// If argument is volatile. also ignore that
template <typename T>
void f_val(T param) { // param is passed by value
	;
}

// Use case
template<typename T, std::size_t N>
constexpr std::size_t array_size(T (&)[N]) noexcept {
	return N;
}

void func(int i, double d) { // function type is void (int, double)
	;
}

int main() {
	int x = 27;         // x ia an int
	const int cx = x;   // cx is a const int
	const int& rx = x;  // rx is a reference to x as a const int
	const int* px = &x; // px is a pointer to x as a const int

	// Case 1
	f_ref(x);			// T is int, param's type is int&
	f_ref(cx);			// T is const int, param's type is const int&
	f_ref(rx);			// T is const int, param's type is const int&

	f_const_ref(x);		// T is int, param's type is const int&
	f_const_ref(cx);	// T is int, param's type is const int&
	f_const_ref(rx);	// T is int, param's type is const int&

	f_pointer(&x);		// T is int, param's type is int*
	f_pointer(px);		// T is const int, param's type is const int*
	

	// Case 2
	f_ref_ref(x);		// T is int&, param's type is also int&
	f_ref_ref(cx);		// T is const int&, param's type is const int&
	f_ref_ref(rx);		// T is const int&, param's type is const int&
	f_ref_ref(27);		// T is int, param's type is int&&

	// Case 3
	f_val(x);			// T is int, param's type is also int
	f_val(cx);			// T is int, param's type is also int
	f_val(rx);			// T is int, param's type is also int
	const char* const ptr = "Fun with pointers"; // prt is const pointer to const object
	f_val(ptr);         // T and param's type is const char*. The constness of what ptr points to
						// is preserved during type deduction, but the constness of ptr itself is
						// ignored when copying it to create the new pointer, param.

	// Array Arguments
	const char name[] = "Akshay Nikam"; // name's type is const char[13]
	f_val(name);		// T is deduced to be const char*
	f_ref(name);		// T is deduced to be const char (&)[13]
	std::cout << array_size(name) << std::endl;

	// Function Arguments
	f_val(func);		// param deduced as ptr-to-func;
						// type is void (*)(int, double)
	f_ref(func);		// param deduced as ref-to-func;
						// type is void (&)(int, double)

    return 0;
}
