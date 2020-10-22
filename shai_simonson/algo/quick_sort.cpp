#include <iostream>
using namespace std;

void swap(int* arr, int i, int j) {
    //cout << "swap : " << i << ", " << j << endl;
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

int partition(int arr[], int l, int h) {
    int pivot = l;
    int i = l + 1;
    int j = h;

    while (i <= j) {
        while (i <= h && arr[pivot] > arr[i]) i++;
        while (j >= l && arr[pivot] < arr[j]) j--;
        //cout << i << " : " << j << endl;
        if (i < j) swap(arr, i, j);
    }

    swap(arr, j, pivot);

    return j;
}

void sort(int* arr, int l, int h) {
    if (l < h) {
        int m = partition(arr, l, h);
        sort(arr, l, m - 1);
        sort(arr, m + 1, h);
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
    //cout << partition(arr, 0, n - 1) << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
