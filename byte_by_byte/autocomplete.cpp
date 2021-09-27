#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>

using namespace std;

class node {
public:
    string prefix;
    map<char, node*> children;
    bool isword;

    node (string prefix) {
        this->prefix = prefix;
        this->isword = false;
    }
};

node* trie = NULL;

void insert_word(string str) {
    node* cur = trie;
    for (int i = 0; i < str.length(); i++) {
        if (cur->children.end() == cur->children.find(str[i])) {
            cur->children[str[i]] = new node(str.substr(0, i + 1));
        }

        cur = cur->children[str[i]];
        if (i == str.length() - 1) cur->isword = true;
    }
}

void build_trie(vector<string> dict) {
    trie = new node("");
    for (auto str : dict) insert_word(str);
}

void find_all_children(node* cur) {
    if (cur->isword) cout << cur->prefix << " ";
    for (auto it : cur->children) {
        find_all_children(it.second);
    }
}

void get_words_for_prefix(string prefix) {
    node* cur = trie;
    for (int i = 0; i < prefix.length(); i++) {
        if (cur->children.end() != cur->children.find(prefix[i]))
            cur = cur->children[prefix[i]];
        else
            return;
    }

    find_all_children(cur);
    cout << endl;
}

void print_trie() {
    node* cur = NULL;
    queue<node*> q;
    q.push(trie);
    while (!q.empty()) {
        cur = q.front();
        q.pop();
        cout << cur->prefix << " : " << cur->children.size() << endl;
        for (auto it : cur->children) {
            cout << it.first << " ";
            q.push(it.second);
        }
    }
}

int main() {
    build_trie(vector<string> {"abc", "acd", "bcd", "def", "a", "aba"});
    get_words_for_prefix("b");
    return 0;
}
