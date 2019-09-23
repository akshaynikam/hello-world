/*
 * Check if subarray with 0 sum is exists or not
 */

#include <iostream>
#include <set>

int found(int arr[], int n) {
	int sum = 0;
	std::set<int> hash;

	hash.insert(0);

    for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (hash.find(sum) != hash.end()) return 1;
		hash.insert(sum);
	}

	return 0;
}

int main() {
	int a1[] = {4, 1, -3, -2, 5};
	int n = sizeof(a1) / sizeof(a1[0]);

	found(a1, n) ? 
		std::cout << "Subarray with 0 sum exists\n" :
		std::cout << "Subarray with 0 sum not exists\n";

	int a2[] = {4, 1, -3, -2};
	n = sizeof(a2) / sizeof(a2[0]);

	found(a2, n) ? 
		std::cout << "Subarray with 0 sum exists\n" :
    	std::cout << "Subarray with 0 sum not exists\n";
	
	int a3[] = {5, 1, -3, -2};
	n = sizeof(a3) / sizeof(a3[0]);

	found(a3, n) ? 
		std::cout << "Subarray with 0 sum exists\n" :
    	std::cout << "Subarray with 0 sum not exists\n";

	return 0;
}
