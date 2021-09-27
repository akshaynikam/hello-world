#include <iostream>
#include <algorithm>

using namespace std;

void threesum(int arr[], int n) {
    sort(arr, arr + n);

    for (int i = 0; i < n - 3; i++) {
        if (i == 0 || arr[i] > arr[i - 1]) {
            int start = i + 1;
            int end = n - 1;

            while (start < end) {
                if (arr[i] + arr[start] + arr[end] == 0) {
                    cout << "[" << arr[i] << ", " << arr[start] << ", " << arr[end] << "]\n";
                }

                if (arr[i] + arr[start] + arr[end] < 0) {
                    int currentStart = start;
                    while (arr[start] == arr[currentStart] && start < end)
                        start++;
                } else {
                    int currentEnd = end;
                    while (arr[end] == arr[currentEnd] && start < end)
                        end--;
                }
            }
        }
    }
}

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    threesum(arr, sizeof(arr)/sizeof(arr[0]));
    return 0;
}
