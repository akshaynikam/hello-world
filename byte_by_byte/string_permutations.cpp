#include <iostream>
#include <string>

using namespace std;

void permutations(string prefix, string suffix) {
    if (0 == suffix.length()) {
        cout << prefix << endl;
    } else {
        for (int i = 0; i < suffix.length(); i++)
            permutations(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1));
    }
}

int main() {
    permutations("", "abc");

    return 0;
}
