#include <iostream>
using namespace std;

#define LEFT(i) ((i * 2) + 1)
#define RIGHT(i) ((i * 2) + 2)
#define PARENT(i) (((i & 1) == 0) ? ((i / 2) - 1) : (i / 2))

void swap(int* arr, int i, int j) {
    int t = arr[i];
    arr[i] = arr[j];
    arr[j] = t;
}

void heapify(int* arr, int i, int n) {
    int largest = i;

    if (LEFT(i) < n && arr[LEFT(i)] > arr[largest])
        largest = LEFT(i);
    if (RIGHT(i) < n && arr[RIGHT(i)] > arr[largest])
        largest = RIGHT(i);
    if (i != largest) {
        swap(arr, i, largest);
        heapify(arr, largest, n);
    }
}

void sort(int* arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, i, n);

    for (int i = n - 1; i > 0; i--) {
        swap(arr, i, 0);
        heapify(arr, 0, i);
    }
}

int main() {
    int* arr;
    int n;

    cin >> n;

    arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    sort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}
