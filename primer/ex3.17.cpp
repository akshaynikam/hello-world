#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

int main() {
	vector<string> words;
	string str;

	while (cin >> str)
		words.push_back(str);
	
	for (auto& s : words) {
		for (auto& ch : s)
			ch = toupper(ch);
	}

	for (auto s : words) cout << s << " ";
	cout << endl;

	return 0;
}
