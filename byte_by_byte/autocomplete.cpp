#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

class autocomplete {
    class node {
    public:
        string prefix;
        char c;
        map<char, node*> children;
        bool word;
        
        node(char c, string prefix) {
            this->c = c;
            this->prefix = prefix;
        }
    };

    node* root;
public:
    autocomplete() {
        root = new node('/', "");
        root->word = false;
    }
    void add_word(string str) {
        node* cur = root;
        for (int i = 0; i < str.length(); i++) {
            if (cur->children.end() == cur->children.find(str[i])) {
                cur->children[str[i]] = new node(str[i], str.substr(0, i + 1));
            }

            cur = cur->children[str[i]];
            if (i == str.length() - 1)
                cur->word = true;
        }
    }

    void get_words(string str) {
        node* cur = root;
        for (int i = 0; i < str.length(); i++) {
            if (cur->children.end() == cur->children.find(str[i])) {
                break;
            }

            cur = cur->children[str[i]];
            //if (cur->word)
            //    cout << cur->prefix << " ";
        }

        if (cur->c == str[str.length() - 1]) {
            queue<node*> q;
            q.push(cur);
            while (!q.empty()) {
                node* temp = q.front();
                q.pop();
                if (temp->word)
                    cout << temp->prefix << " ";
                for (auto it : temp->children) {
                    q.push(it.second);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    autocomplete ac;
    ac.add_word("abc");
    ac.add_word("acd");
    ac.add_word("bcd");
    ac.add_word("def");
    ac.add_word("a");
    ac.add_word("aba");

    ac.get_words("ab");
    ac.get_words("a");
    ac.get_words("b");
    ac.get_words("ak");
    return 0;
}
