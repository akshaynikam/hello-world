#include <iostream>

using namespace std;

int main() {
	int arr[] = {0, 1, 2, 3, 4};

	auto ptr = arr;

	auto ab = begin(arr);
	auto ae = end(arr);
	//auto pb = begin(ptr);
	//auto pe = end(ptr);

	cout << ab << " : " << ae << endl;
	//cout << pb << " : " << pe << endl;

	return 0;
}
