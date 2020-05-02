#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<unsigned> scores(11, 0);
	vector<unsigned> grade = {42, 65, 95, 100, 39, 67, 95, 76, 88, 76, 83, 92, 76, 93};

	auto beg = scores.begin();
	for (auto g : grade) {
		if (g <= 100)
			++(*(beg + (g/10)));
	}

	for (auto s : scores) cout << s << " ";
	cout << endl;

	return 0;
}
