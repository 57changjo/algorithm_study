#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>

int dp[1001][1001];
std::string str1, str2;

void inputData() {
    std::cin >> str1 >> str2;
    str1 = " " + str1;
    str2 = " " + str2;
}

void printData() {
    std::cout << str1 << '\n' << str2 << '\n';
}

void solve() {
    int len1 = str1.length() - 1;
    int len2 = str2.length() - 1;

    for (int i = 1; i <= len1; ++i) {
        for (int j = 1; j <= len2; ++j) {
            if (str1[i] == str2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    std::cout << dp[len1][len2];
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //(void)freopen("b9251.txt", "r", stdin);
    inputData();
	//printData();
    solve();

    return 0;
}
