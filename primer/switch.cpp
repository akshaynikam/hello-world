#include <iostream>

using namespace std;

int main() {
	int i = 1;

	while (i <= 10) {
		switch (i) {
			case 3:
				break;
			default:
				i++;
				continue;
		}

		cout << i << " ";
		i++;
	}

	cout << endl;
}
