#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int i;

	while (cin >> i)
		v.push_back(i);
	
	decltype(v.size()) size = v.size();
	for (int j = 0; j < size; j++) {
		if (j != size - j - 1)
			cout << v[j] + v[size - j - 1] << " ";
		else
			cout << v[j] << " ";
	}

	cout << endl;

	return 0;
}
