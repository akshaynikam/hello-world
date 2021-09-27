#include <iostream>
#include <algorithm>
#include <string>
#include <map>

int longest_substring(std::string str) {
    int start = 0;
    std::map <char, int> hash;

    int length = 0;
    for (int end = 0; end < str.length(); end++) {
        char c = str[end];

        if (hash.end() != hash.find(c)) {
            if (start <= hash[c]) {
                start = hash[c];
            }
        }

        length = std::max(length, end - start);
        hash[c] = end;
    }

    return length;
}

int main(int argc, char** argv) {
    std::cout << longest_substring(argv[1]) << std::endl;

    return 0;
}
