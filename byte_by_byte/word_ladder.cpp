#include <iostream>
#include <set>
#include <map>
#include <string>
#include <queue>

using namespace std;

bool is_next_word(string str1, string str2) {
    for (int i = 0; i < str1.length(); i++) {
        if ((str1.substr(0, i) == str2.substr(0, i)) &&
            (str1.substr(i + 1, str1.length() - i) == str2.substr(i + 1, str2.length() - i)))
            return true;
    }

    return false;
}

int word_ladder(set<string>& words, string begin, string end) {
    queue<string> q;
    map<string, string> m;
    
    if (words.end() == words.find(end)) return 0;

    q.push(begin);

    while (!q.empty()) {
        string cur = q.front();
        q.pop();
        for (auto it : words) {
            if (m.end() != m.find(it)) continue;
            if (is_next_word(cur, it)) {
                m[it] = cur;
                words.erase(it);
                q.push(it);
                if (it == end) {
                    string temp = it;
                    int ret = 1;
                    while (temp != begin) {
                        //cout << m[temp] << " ";
                        temp = m[temp];
                        ret++;
                    }
                    return ret;
                }
            }
        }
    }

    return 0;
}

int main() {
    set<string> words = {"poon", "plee", "same", "poie", "plea", "plie", "poin"};
    //set<string> words = {"hot","dot","dog","lot","log","cog"};

    cout << word_ladder(words, "toon", "plea") << endl;
    //cout << word_ladder(words, "hit", "cog") << endl;

    return 0;
}
