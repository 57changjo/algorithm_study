#include <iostream>
#include <algorithm>
#include <string>

#if 1
int main(void) {

    std::string A, B;
    std::cin >> A >> B;

    int n = A.size(), m = B.size();
    int dp[1001][1001] = { 0 };

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (A[i - 1] == B[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;

            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    std::cout << dp[n][m];

    return 0;
}
#endif
