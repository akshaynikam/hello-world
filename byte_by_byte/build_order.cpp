#include <iostream>
#include <vector>

using namespace std;

void dfs(int arr[7][7], int v, int visited[], vector<int>& result) {
    //cout << "dfs : " << v << endl;
    if (visited[v] == 0) return;
    visited[v] = 0;

    for (int i = 0; i < 7; i++) {
        if (arr[v][i] && visited[i] != 1)
            dfs(arr, i, visited, result);
    }

    visited[v] = 1;
    result.push_back(v);
}

int main() {
    int arr[7][7] = {0, 1, 0, 0, 0, 0, 0,
                     0, 0, 1, 0, 0, 0, 0,
                     0, 0, 0, 0, 0, 0, 0,
                     1, 0, 0, 0, 1, 0, 0,
                     0, 0, 0, 0, 0, 1, 0,
                     0, 0, 0, 0, 0, 0, 1,
                     0, 1, 1, 0, 0, 0, 0};

    int visited[7] = {-1, -1, -1, -1, -1, -1, -1};
    vector<int> result;

    for (int i = 0; i < 7; i++)
        if (visited[i] != 1)
            dfs(arr, i, visited, result);

    for (auto it : result) cout << it << " ";
    cout << endl;
}
