#include <iostream>
#include <vector>
#include <map>
#include <string>

void substring_with_concat_words(std::string str, std::vector<std::string>& list) {
    std::map<std::string, int> hash;

    int words_count = list.size();
    int word_size = list[0].size();
    int words_length = words_count * word_size;

    for (int i = 0; i < words_count; i++)
        hash[list[i]]++;

    for (int i = 0; i < str.size() - words_length; i++) {
        std::map<std::string, int> temp_hash(hash);
        int j = i;
        int count = words_count;
        while (j < i + words_length) {
            std::string word = str.substr(j, word_size);
            if (hash.end() == hash.find(word) ||
                temp_hash[word] == 0)
                break;
            else {
                temp_hash[word]--;
                count--;
            }

            j += word_size;
        }

        if (count == 0) {
            std::cout << i << " ";
        }
    }
    std::cout << std::endl;

}

int main() {
    std::vector<std::string> list = {"bar","foo","the"};
    substring_with_concat_words("barfoofoobarthefoobarman", list);
    return 0;
}
