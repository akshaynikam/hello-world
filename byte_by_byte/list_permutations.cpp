#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr) {
    for (auto it : arr)
        cout << it << " ";
    cout << endl;
}

void permutations(vector<int> arr, int start) {
    if (start >= arr.size())
        print(arr);
    else {
        for (int i = start; i < arr.size(); i++) {
            swap(arr[start], arr[i]);
            permutations(arr, start + 1);
            swap(arr[start], arr[i]);
        }
    }
}

int main() {
    permutations(vector<int> {1, 2, 3}, 0);
    return 0;
}
