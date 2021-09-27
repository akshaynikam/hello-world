#include <iostream>
#include <cstring>

void print_anagrams(char* text, char* pattern) {
    int m = strlen(pattern);
    int n = strlen(text);

    int countT[256] = {0};
    int countP[256] = {0};

    for (int i = 0; i < m; i++) {
        countT[text[i]]++;
        countP[pattern[i]]++;
    }

    std::cout << "[";
    for (int i = m; i < n; i++) {
        if (!memcmp(countT, countP, 256 * sizeof(int)))
            std::cout << " " << i - m;

        countT[text[i]]++;
        countT[text[i - m]]--;
    }

    if (!memcmp(countT, countP, 256 * sizeof(int)))
        std::cout << " " << n - m;
    std::cout << " ]\n";
}


int main(int argc, char** argv) {
    print_anagrams(argv[1], argv[2]);

    return 0;
}
