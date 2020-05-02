#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int i;

	while (cin >> i)
		v.push_back(i);
	
	auto beg = v.begin();
	auto end = v.end() - 1;

	for (; beg != v.end(); beg++, end--) {
		if (beg != end)
			cout << *beg + *end << " ";
		else
			cout << *beg << " ";
	}

	cout << endl;

	return 0;
}
