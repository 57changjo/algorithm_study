#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, K;
int coin[101];
int dp[10001];

void inputData(void) {
    (void)scanf("%d %d", &N, &K);
    for (int i = 1; i <= N; i++) {
        (void)scanf("%d", &coin[i]);
    }
}

void solve(void) {
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
		// j는 현재 동전 가치보다 작을 수 없음
        for (int j = coin[i]; j <= K; j++) {

			// 기존 j원을 만들던 경우의 수에 coin[i]을 썼을 때 경우의 수를 더함
            // coin[i]를 쓴다는 것은, j-coin[i]원을 만드는 경우에 coin[i]를 추가하는 것!
			dp[j] = dp[j] + dp[j - coin[i]];
        }
    }
    // 5, 2, 1원 순서로 입력되어도 상관이 없음
    // coin 배열에서 큰 동전을 먼저 집어와도, 스스로를 더하는 메커니즘이므로 놓치는 경우가 없다
    printf("%d", dp[K]);
}

int main(void) {
    //(void)freopen("b2293.txt", "r", stdin);
    inputData();
    solve();

    return 0;
}

#endif
