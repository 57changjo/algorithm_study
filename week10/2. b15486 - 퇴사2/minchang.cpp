#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#define MAX_N (1500000+1)

using namespace std;

int N;
int T[MAX_N];
int P[MAX_N];
int dp[MAX_N + 1];

void inputData(void) {
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }
}

void solve(void) {

    for (int i = N; i >= 1; --i) {
        int next_day = i + T[i];

        if (next_day > N + 1) {
			// 상담 시 퇴사일 넘길 때 -> 상담 불가
            // i일의 최대 수익 = i+1 일의 최대 수익
            dp[i] = dp[i + 1];
        }
        else {
            // 오늘 상담 X vs 오늘 상담 O
            // 내일 부터 최대 수익 vs 오늘 상담 + 다음 상담일부터 최대 수익
            dp[i] = max(dp[i + 1], P[i] + dp[next_day]);
        }
    }

    cout << dp[1];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b15486.txt", "r", stdin);

    inputData();
    solve();

    return 0;
}
