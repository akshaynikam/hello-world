#include <iostream>
#include <set>

void consecutive(int arr[], int n) {
    std::set<int> hashSet;

    for (int i = 0; i < n; i++) {
        hashSet.insert(arr[i]);
    }

    int maxLength = 0;
    for (auto i : hashSet) {
        std::cout << i << " ";
        if (hashSet.end() != hashSet.find(i - 1)) {
            //std::cout << "continue\n";
            continue;
        }
        int length = 0;
        while (hashSet.end() != hashSet.find(i++)) length++;
        maxLength = maxLength < length ? length : maxLength;
    }

    std::cout << maxLength << std::endl;
}

int main() {
    int arr[] = {8, 7, 1, 6, 5};

    consecutive(arr, 5);

    return 0;
}
