#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void compress(string str) {
    stringstream result;
    int sum = 1;

    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == str[i + 1])
            sum++;
        else {
            result << str[i] << sum;
            sum = 1;
        }
    }

    result << str[str.length() - 1] << sum;
    if (result.str().length() <= str.length())
        cout << result.str() << endl;
    else
        cout << str << endl;
}

int main(int argc, char** argv) {

    compress(argv[1]);
    return 0;
}
