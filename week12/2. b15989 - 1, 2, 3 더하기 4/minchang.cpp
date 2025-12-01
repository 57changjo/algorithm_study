#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001];

void inputData(void) {
    // dp[i]: 합이 i가 되는 경우의 수

    // 모든 수를 1을 더해서 만드는 건 항상 존재
    // dp[0] = 1도 초기화용
    for (int i = 0; i <= 10000; i++) {
        dp[i] = 1;
    }

	// 나보다 2 작은 수의 경우의 수들에 2를 더하면 나를 만들 수 있음
    for (int i = 2; i <= 10000; i++) {
        dp[i] += dp[i - 2];
    }

	// 나보다 3 작은 수의 경우의 수들에 3을 더하면 나를 만들 수 있음
    for (int i = 3; i <= 10000; i++) {
        dp[i] += dp[i - 3];
    }
}

int solve(void) {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // (void)freopen("b15989.txt", "r", stdin);

    inputData();
    solve();

    return 0;
}
