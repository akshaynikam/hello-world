#include <iostream>
#include <cstdlib>
using namespace std;

void sort(int* arr, int n, int k) {
    int *count = (int *) calloc(k, sizeof(int));
    int *aux = new int [n];

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = 0; i < n; i++) {
        aux[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = aux[i];
    }
}

int main() {
    int* arr;
    int n, k;

    cin >> n >> k;

    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, n, k);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
