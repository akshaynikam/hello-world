#include <iostream>

using namespace std;

int main() {
	int arr[10] = {0};
	int pos = 0;

	for (auto& i : arr) {
		i = pos++;
	}

	for (auto i : arr) cout << i << " ";
	cout << endl;

	return 0;
}
