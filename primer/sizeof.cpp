#include <iostream>
#include <vector>

using namespace std;

class demo {
	public: int ele;
};

int main() {
	cout << (sizeof demo::ele) << endl;// 4

	vector<int> v = {1, 2, 3, 4, 5, 6};
	string str("AkshayNikamPune");

	cout << sizeof(v) << endl;//24
	cout << sizeof(str) << endl;//8
	cout << sizeof(vector<int>) << endl;//24

	return 0;
}
