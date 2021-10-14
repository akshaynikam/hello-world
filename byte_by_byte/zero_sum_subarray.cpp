#include <iostream>
#include <map>

using namespace std;

void zero_sum(int arr[], int n) {
    map<int, int> hash;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (hash.find(sum) != hash.end()) {
            cout << hash[sum] << ", " << i - 1 << endl;
            return;
        }

        hash[sum] = i;
        sum += arr[i];
    }
}

int main() {
    int arr[] = {1, 2, -5, 1, 2, -1};

    for (auto i : arr) cout << i << " ";
    cout << endl;

    zero_sum(arr, sizeof(arr)/sizeof(arr[0]));

    return 0;
}
