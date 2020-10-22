#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void bktsort(float arr[], int n) {
    vector<float> aux[n];

    for (int i = 0; i < n; i++) {
        int bi = n * arr[i];
        aux[bi].push_back(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        sort(aux[i].begin(), aux[i].end());
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < aux[i].size(); j++) {
            arr[idx++] = aux[i][j];
        }
    }
}

int main() 
{ 
    float arr[] = { 0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    bktsort(arr, n); 
  
    cout << "Sorted array is \n"; 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
    return 0; 
}
