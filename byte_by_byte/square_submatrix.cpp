#include <iostream>

using namespace std;

void max_square(int arr[][5], int n) {
    int dp[100][100] = {0};
    int row = 0;
    int col = 0;
    int max_length = 0;

    for (int i = 0; i < n; i++) {
        dp[i][0] = arr[i][0];
        dp[0][i] = arr[0][i];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (arr[i][j])
                dp[i][j] = std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            if (max_length < dp[i][j]) {
                max_length = dp[i][j];
                row = i;
                col = j;
            }
        }
    }

    cout << "arr[" << row << ", " << col << "] : " << max_length << endl;
}

int main() {
    int arr[5][5] = {1, 1, 1, 1, 1,
                     1, 1, 1, 1, 0,
                     1, 1, 1, 1, 0,
                     1, 1, 1, 1, 0,
                     1, 0, 0, 0, 0};

    max_square(arr, 5);
}
