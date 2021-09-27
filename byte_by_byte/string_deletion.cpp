#include <iostream>
#include <string>
#include <queue>
#include <set>

using namespace std;

int string_delete(string query, set<string> dictionary) {
    queue<string> q;

    q.push(query);

    while (!q.empty()) {
        string str = q.front();
        q.pop();

        for (int i = 0; i < str.length(); i++) {
            string sub = str.substr(0, i) + str.substr(i + 1, str.length() - (i + 1));
            if (dictionary.end() != dictionary.find(sub))
                return query.length() - sub.length();
            q.push(sub);
        }
    }

    return -1;
}

int main() {
    set<string> dict = {"a", "aa", "abc"};

    cout << string_delete("akbhac", dict) << endl;
    return 0;
}
