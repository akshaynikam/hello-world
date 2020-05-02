#include <iostream>

using namespace std;

int main() {
	int ia[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

	// version 1
	cout << "Version 1\n";
	for (auto &row : ia) {
		for (auto &col : row)
			cout << col << ' ';
		cout << endl;
	}

	// version 2
	cout << "\nVersion 2\n";
	for (int (*r)[4] = ia; r != ia + 3; r++) {
		for (int *c = *r; c != *r + 4; c++) {
			cout << *c << ' ';
		}

		cout << endl;
	}

	return 0;
}
