#include <iostream>
#include <cstring>

void minimum_window_substring(const char* text, const char* pat) {
    int hashT[256] = {0};
    int hashP[256] = {0};
    int len1 = strlen(text);
    int len2 = strlen(pat);

    for (int i = 0; i < len2; i++)
        hashP[pat[i]]++;

    int start = 0;
    int start_index = -1;
    int min_len = len1 + 1;
    int count = 0;
    int j;

    for (j = 0; j < len1; j++) {
        hashT[text[j]]++;

        if (hashT[text[j]] <= hashP[text[j]])
            count++;

        if (count == len2) {
            while (hashT[text[start]] > hashP[text[start]] ||
                   hashP[text[start]] == 0) {
                if (hashT[text[start]] > hashP[text[start]]) {
                    hashT[text[start]]--;
                    start++;
                }
            }

            int win_len = j - start + 1;
            if (min_len > win_len) {
                min_len = win_len;
                start_index = start;
            }
        }
    }

    if (start_index == -1)
        std::cout << "\n";
    else {
        while (min_len) {
            std::cout << text[start_index++];
            min_len--;
        }

        std::cout << std::endl;
    }
}


int main() {
    minimum_window_substring("acbdnracbn", "acbdnracbn");

    return 0;
}
