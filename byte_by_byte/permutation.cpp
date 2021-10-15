#include <iostream>
#include <string>

using namespace std;

void permut(string prefix, string suffix) {
    if (suffix == "") cout << prefix << endl;
    else {
        for (int i = 0; i < suffix.length(); i++)
            permut(prefix + suffix[i], suffix.substr(0, i) + suffix.substr(i + 1));
    }
}

void permut(int arr[], int start, int n) {
    if (start == n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
        return;
    } else {
        for (int i = start; i < n; i++) {
            swap(arr[i], arr[start]);
            permut(arr, start + 1, n);
            swap(arr[i], arr[start]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};

    permut(arr, 0, 3);
    permut("", "123");

    return 0;
}
