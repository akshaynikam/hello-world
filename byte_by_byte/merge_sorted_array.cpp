#include <iostream>

void merge_array(int a[], int b[], int aLength, int bLength) {
    int aI = aLength - 1;
    int bI = bLength - 1;
    int mI = aLength + bLength - 1;

    while (aI >= 0 && bI >= 0) {
        if (a[aI] > b[bI]) {
            a[mI--] = a[aI--];
        } else {
            a[mI--] = b[bI--];
        }
    }

    while (bI >= 0) {
        a[mI--] = b[bI--];
    }
}

void print(int a[], int n) {
    for (int i = 0; i < n; i++) {
        std::cout << a[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    int a[] = {1, 3, 5, 0, 0, 0};
    int b[] = {2, 4, 6};

    merge_array(a, b, 3, 3);
    print(a, 6);

    return 0;
}
