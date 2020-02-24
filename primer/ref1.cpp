#include <iostream>

int main() {
	//int pi = 3;
	double pi = 3;
	/*
	 * below statement will be transform by the compiler like:
	 * const int temp = pi;
	 * const int &r = temp;
	 */
	const int &r = pi;

	pi = 2;

	std::cout << pi << " : " << r << std::endl;

	return 0;
}
