#include <iostream>
#include <string>
#include <set>

using namespace std;

string get_lcp(string str1, string str2) {
    int i = 0;
    while (i < str1.length() && i < str2.length() && str1[i] == str2[i])
        i++;

    return str1.substr(0, i);
}

string lcp(set<string> list) {
    if (list.size() < 2) return "";
    auto it = list.begin();
    string str1 = *it;
    if (list.size() == 2) {
        it++;
        return get_lcp(str1, *it);
    }

    list.erase(it);
    return get_lcp(str1, lcp(list));
}

int main() {
    //lcp((set<string>){"ak", "aksh"});
    cout << lcp((set<string>){"geeksforgeeks", "geeks", "geek", "geezer"}) << endl;
    return 0;
}
