/* 
 * Find pair with given sum in the array
 */

#include <iostream>
#include <set>

void findPair(int arr[6], int n, int sum) {
	std::set<int> hash;

	for (int i = 0; i < n; i++) {
		if (hash.find(sum - arr[i]) != hash.end()) {
			std::cout << "Pair found for " << sum << "\n";
			return;
		}

		hash.insert(arr[i]);
	}

	std::cout << "Pair not found for " << sum << std::endl;
}

int main() {
    int arr[6] = {8, 7, 2, 5, 3, 1};
    int n = sizeof(arr)/sizeof(arr[0]);

	findPair(arr, n, 10);
	findPair(arr, n, 11);
	findPair(arr, n, 20);
	return 0;
}
