#include <iostream>
#include <string>

using namespace std;

int edit_distance(string str1, string str2, int m, int n) {
    if (m == 0)
        return n;
    if (n == 0)
        return m;
    if (str1[m - 1] == str2[n - 1])
        return edit_distance(str1, str2, m - 1, n - 1);
    return 1 + min(edit_distance(str1, str2, m - 1, n),
                   min(edit_distance(str1, str2, m, n - 1),
                   edit_distance(str1, str2, m - 1, n - 1)));
}

int dp_edit_distance(string str1, string str2, int m, int n) {
    int **dp = new int*[m + 1];

    for (int i = 0; i <= m; i++)
        dp[i] = new int[n + 1];

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(str1[i - 1] == str2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j], dp[i - 1][j - 1]));
        }
    }

    return dp[m][n];
}

int main() {
    std::cout << edit_distance("horse", "ros", 5, 3) << std::endl;
    std::cout << dp_edit_distance("horse", "ros", 5, 3) << std::endl;

    return 0;
}
