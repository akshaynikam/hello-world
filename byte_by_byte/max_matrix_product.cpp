#include <iostream>

int max(int i, int j) {
    return i > j ? i : j;
}

int min(int i, int j) {
    return i < j ? i : j;
}

int max_prod(int (*arr)[3], int row, int col, int i, int j) {
    if ((i == (row - 1)) && (j == (col - 1)))
        return arr[i][j];

    if (i == row - 1)
        return arr[i][j] * max_prod(arr, row, col, i, j + 1);

    if (j == col - 1)
        return arr[i][j] * max_prod(arr, row, col, i + 1, j);

    return arr[i][j] * (max(max_prod(arr, row, col, i, j + 1),
                           max_prod(arr, row, col, i + 1, j)));
}

int bottom_up(int (*arr)[3], int row, int col) {
    int** maxCache = new int*[row];
    int** minCache = new int*[row];
    for (int i = 0; i < row; i++) {
        maxCache[i] = new int[col];
        maxCache[0][i] = arr[0][i];
        maxCache[i][0] = arr[i][0];
        minCache[i] = new int[col];
        minCache[0][i] = arr[0][i];
        minCache[i][0] = arr[i][0];
    }

    for (int i = 1; i < row; i++) {
        for (int j = 1; j < col; j++) {
            maxCache[j][0] = maxCache[j - 1][0] * arr[j][0];
            maxCache[0][j] = maxCache[0][j - 1] * arr[0][j];
            minCache[j][0] = maxCache[j - 1][0] * arr[j][0];
            minCache[0][j] = maxCache[0][j - 1] * arr[0][j];
            if (arr[i][j] < 0) {
                maxCache[i][j] = arr[i][j] * min(minCache[i][j - 1], minCache[i - 1][j]);
                minCache[i][j] = arr[i][j] * max(maxCache[i][j - 1], maxCache[i - 1][j]);
            } else {
                maxCache[i][j] = arr[i][j] * max(maxCache[i][j - 1], maxCache[i - 1][j]);
                minCache[i][j] = arr[i][j] * min(minCache[i][j - 1], minCache[i - 1][j]);
            }
        }
    }

    return maxCache[row - 1][col - 1];
}

int main() {
    int arr[3][3] = {{-1, 2, 3},
                     {4, 5, -6},
                     {7, 8, 9}};

    std::cout << max_prod(arr, 3, 3, 0, 0) << std::endl;
    std::cout << bottom_up(arr, 3, 3) << std::endl;

    return 0;
}
