#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
int stairs[301];
// i번째 계단 도달 시 최대 점수
int dp[301];

void inputData(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }
}

void solve(void) {

    dp[0] = 0;
    dp[1] = stairs[1];

    if (N == 1) {
        cout << dp[1];
        return;
    }

    dp[2] = stairs[1] + stairs[2];

    if (N == 2) {
        cout << dp[2];
        return;
    }

    for (int i = 3; i <= N; i++) {

        int case1 = dp[i - 2] + stairs[i];
        int case2 = dp[i - 3] + stairs[i - 1] + stairs[i];

        dp[i] = max(case1, case2);
    }

    cout << dp[N];
}

int main(void) {
    //(void)freopen("b2579.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    inputData();
    solve();

    return 0;
}
