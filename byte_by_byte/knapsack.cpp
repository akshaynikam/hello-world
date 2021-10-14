#include <iostream>

using namespace std;

int knapsack_rec(int weight[], int val[], int W, int n) {
    if (n == 0 || W == 0) return 0;

    if (weight[n - 1] > W) return knapsack_rec(weight, val, W, n - 1);
    return max(knapsack_rec(weight, val, W, n - 1),
               knapsack_rec(weight, val, W - weight[n - 1], n - 1) + val[n - 1]);
}

int knapsack_dp(int weight[], int val[], int W, int n) {
    int cache[4][6] = {0};

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if (j < weight[i - 1])
                cache[i][j] = cache[i - 1][j];
            else {
                cache[i][j] = max(cache[i - 1][j], cache[i - 1][j - weight[i - 1]] + val[i - 1]);
            }
        }
    }

    return cache[n][W];
}

int main() {
    int weight[] = {1, 2, 3};
    int val[] = {6, 10, 12};

    cout << knapsack_rec(weight, val, 5, 3) << endl;
    cout << knapsack_dp(weight, val, 5, 3) << endl;

    return 0;
}
