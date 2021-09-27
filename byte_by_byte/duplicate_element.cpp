#include <iostream>
#include <cstring>

void duplicate(int* a, int n) {
    int *hash = new int[n];

    memset(hash, 0, n);
    for (int i = 0; i < n; i++)
        hash[a[i] - 1]++;

    for (int i = 0; i < n; i++)
        if (hash[i] > 1)
            std::cout << i + 1 << " ";
    std::cout << std::endl;
}

int main() {
    int n;

    std::cin >> n;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    duplicate(a, n);

    return 0;
}
