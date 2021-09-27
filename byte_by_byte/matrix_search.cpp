#include <iostream>
#include <cstdlib>

bool search(int (*arr)[4], int n, int m, int x) {
    int row = 0;
    int col = m - 1;

    while (row < n && col >= 0) {
        if (arr[row][col] == x) return true;
        if (arr[row][col] < x) row++;
        else col--;
    }
    return false;
}

int main(int argc, char** argv) {
    int arr[][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    std::cout << search(arr, 3, 4, atoi(argv[1])) << std::endl;

    return 0;
}
