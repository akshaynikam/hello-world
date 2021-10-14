#include <iostream>
#include <set>

using namespace std;

void set_row(int arr[][4], int r, int n) {
    for (int i = 0; i < n; i++) arr[r][i] = 1;
}

void set_col(int arr[][4], int c, int n) {
    for (int i = 0; i < n; i++) arr[i][c] = 1;
}

void print(int arr[][4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

void zero_matrix(int arr[][4], int n) {
    set<pair<int, int> > hash;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j]) hash.insert(pair<int, int> (i, j));

    for (auto it : hash) {
        set_row(arr, it.first, n);
        set_col(arr, it.second, n);
    }
}

int main() {
    int arr[][4] = {1, 0, 0, 0,
                    0, 0, 0, 0,
                    0, 0, 1, 0,
                    0, 0, 0, 0};

    print(arr, 4);
    zero_matrix(arr, 4);
    cout << endl;
    cout << endl;
    print(arr, 4);
    return 0;
}
