#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
	string str;

	cin >> str;

	for (auto c : str) {
		if (!ispunct(c))
			cout << c;
	}

	cout << endl;

	return 0;
}
