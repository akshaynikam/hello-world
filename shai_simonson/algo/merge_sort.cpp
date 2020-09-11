#include <iostream>
using namespace std;

void merge(int* arr, int l, int m, int h) {
    int* res = new int[h - l + 1];
    int i, j, k;
    
    i = l;
    j = m + 1;
    k = 0;

    while (i <= m && j <= h) {
        if (arr[i] < arr[j])
            res[k++] = arr[i++];
        else
            res[k++] = arr[j++];
    }

    while (i <= m)
        res[k++] = arr[i++];

    while (j <= h)
        res[k++] = arr[j++];

    for (i = h, k = k - 1; k >= 0; k--, i--)
        arr[i] = res[k];
}

void sort(int* arr, int l, int h) {
    if (l < h) {
        int m = (l + h) / 2;
        sort(arr, l, m);
        sort(arr, m + 1, h);
        merge(arr, l, m, h);
    }
}

int main() {
    int* arr;
    int n;

    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
