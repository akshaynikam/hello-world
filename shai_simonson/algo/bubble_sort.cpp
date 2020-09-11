#include <iostream>
using namespace std;

void sort(int* arr, int n) {
    int temp;
    bool flag;
    for (int i = 0; i < n - 1; i++) {
        flag = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                flag = true;
            }
        }

        if (flag == false)
            break;
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
