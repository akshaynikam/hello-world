#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int i;

	while (cin >> i) {
		v.push_back(i);
	}

	for (auto j : v)
		cout << j << " ";
	cout << endl;

	return 0;
}
