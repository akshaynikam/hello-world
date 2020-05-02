#include <iostream>

using namespace std;

int main() {
	int ia[2][3] = {0, 1, 2, 3, 4, 5};
	int (*p)[3] = ia;
	//int *ip = ia;

	cout << *ia << endl;
	cout << ia << endl;
	cout << *p << endl;
	//cout << *ip << endl;

	return 0;
}
