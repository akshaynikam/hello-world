#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	vector<string> v;
	string str;

	while (cin >> str) {
		v.push_back(str);
	}

	for (auto j : v)
		cout << j << " ";
	cout << endl;

	return 0;
}
