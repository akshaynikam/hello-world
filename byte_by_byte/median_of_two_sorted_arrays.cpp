#include <iostream>

using namespace std;

double median(int arr[], int n) {
    return ((n % 2 == 0) ? (double)(arr[n / 2 - 1] + arr[n / 2]) / 2 : arr[n / 2]);
}

double median(int arr1[], int arr2[], int n) {
    if (n == 1) return (arr1[0] + arr2[0]) / 2;
    if (n == 2) return (double)(max(arr1[0], arr2[0]) + min(arr1[1], arr2[1])) / 2;
    
    double m1 = median(arr1, n);
    double m2 = median(arr2, n);

    if (m1 == m2) return m1;

    if (m1 < m2) {
        if (n % 2) return median(arr1 + n/2, arr2, n - n/2);
        return median(arr1 + (n/2) - 1, arr2, n - n/2 + 1);
    } else {
        if (n % 2) return median(arr1, arr2 + n/2, n - n/2);
        return median(arr1, arr2 + (n/2) - 1, n - n/2 + 1);
    }
}

int main() {
    int arr1[] = {10, 30, 50, 60, 70, 80};
    int arr2[] = {20, 40, 80, 90, 100, 110};
    cout << median(arr1, arr2, 6) << endl;
    return 0;
}
