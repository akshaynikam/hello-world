#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v1;
	vector<int> v2(10);
	vector<int> v3(10, 42);
	vector<int> v4{10};
	vector<int> v5{10, 42};
	vector<string> v6{10};
	vector<string> v7{10, "hi"};

	cout << v1.size() << " : "; //0
	for (auto it = v1.cbegin(); it != v1.end(); it++) cout << *it << " ";
	cout << endl;

	cout << v2.size() << " : "; //10
	for (auto it = v2.cbegin(); it != v2.end(); it++) cout << *it << " ";
	cout << endl;

	cout << v3.size() << " : "; //10
	for (auto it = v3.cbegin(); it != v3.end(); it++) cout << *it << " ";
	cout << endl;
	
	cout << v4.size() << " : "; //1
	for (auto it = v4.cbegin(); it != v4.end(); it++) cout << *it << " ";
	cout << endl;

	cout << v5.size() << " : "; //2
	for (auto it = v5.cbegin(); it != v5.end(); it++) cout << *it << " ";
	cout << endl;

	cout << v6.size() << " : "; //10
	for (auto it = v6.cbegin(); it != v6.end(); it++) cout << *it << " ";
	cout << endl;

	cout << v7.size() << " : "; //10
	for (auto it = v7.cbegin(); it != v7.end(); it++) cout << *it << " ";
	cout << endl;

	return 0;
}
