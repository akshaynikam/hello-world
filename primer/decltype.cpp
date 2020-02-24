#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v{1};

	decltype(v[0]) r = v[0];

	r = 10;

	cout << v[0] << endl;

	return 0;
}
