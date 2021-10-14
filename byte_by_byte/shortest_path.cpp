#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>

using namespace std;

class graph {
     struct node {
        int vertex;
        list<int> children;
     };

     node* v;
     int n;

public:
    graph(int n) {
        this->n = n;
        v = new node[n];
        for (int i = 0; i < n; i++)
            v[i].vertex = i;
    }

    void add_edge(int a, int b) {
        v[a].children.push_back(b);
    }

    void print() {
        for (int i = 0; i < n; i++) {
            cout << v[i].vertex + 1 << " => ";
            for (auto it : v[i].children) {
                cout << it + 1 << " => ";
            }

            cout << "NULL\n";
        }
    }

    void shortest_path(int a, int b) {
        queue<int> q;
        map<int, int> hash;
        hash[-1] = a;

        q.push(a);
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (cur == b) break;
            for (auto it : v[cur].children) {
                if (hash.end() == hash.find(it)) {
                    hash[it] = cur;
                    q.push(it);
                }
            }
        }

        if (!q.empty()) {
            cout << b << " ";
            while (hash[b] != a) {
                cout << hash[b] << " ";
                b = hash[b];
            }

            cout << a << endl;
        }
    }
};

int main() {
    graph g(5);
    g.add_edge(0, 1);
    g.add_edge(0, 2);
    g.add_edge(1, 4);
    g.add_edge(3, 0);
    g.add_edge(3, 2);
    g.add_edge(4, 3);

    g.print();
    g.shortest_path(1, 2);

    return 0;
}
