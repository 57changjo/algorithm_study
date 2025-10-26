#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000;
int dp[MAX + 1][MAX + 1];

int main() {
    string A, B;
    cin >> A >> B;

    int lenA = A.length();
    int lenB = B.length();

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[lenA][lenB] << '\n';
    return 0;
}
