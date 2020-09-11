#include <iostream>
using namespace std;

void sort(int* arr, int n) {
    int temp;

    for (int i = 1; i < n; i++) {
        temp = arr[i];
        int j = i - 1;
        while (j >= 0 && temp < arr[j]) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
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
