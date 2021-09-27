#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <set>

using namespace std;

bool is_anagram(string str1, string str2) {
    int hash1[256] = {0};
    int hash2[256] = {0};
    
    for (int i = 0; i < str1.length(); i++) hash1[str1[i]]++;
    for (int i = 0; i < str2.length(); i++) hash2[str2[i]]++;

    return !memcmp(hash1, hash2, sizeof(int) * 256);
}

void group_anagram(set<string> strs) {
    map<string, set<string> > hash;

    for (auto it = strs.begin(); it != strs.end(); it++) {
        auto hit = hash.begin();
        while (hit != hash.end()) {
            if (is_anagram(*it, hit->first)) {
                (hit->second).insert(*it);
                break;
            }

            hit++;
        }

        if (hit == hash.end())
            hash[*it] = ((set<string>) {""});
    }

    auto it = hash.begin();
    while (it != hash.end()) {
        cout << "[" << it->first;
        for (auto git = (it->second).begin(); git != (it->second).end(); git++) {
            cout << " " << *git;
        }
        cout << "]  ";
        it++;
    }

    cout << endl;
}

int main() {
    group_anagram((set<string>){"eat","tea","tan","ate","nat","bat"});
    group_anagram((set<string>){"a"});
    group_anagram((set<string>){""});
    return 0;
}
