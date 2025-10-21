#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

enum {
	RED = 0,
	GREEN = 1,
	BLUE = 2
};

int N;
int cost[1001][3];
int dp[1001][3];

int min(int a, int b) {
    return (a < b) ? a : b;
}

void inputData(void) {
    (void)scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        (void)scanf("%d %d %d", &cost[i][RED], &cost[i][GREEN], &cost[i][BLUE]);
    }
}

void solve(void) {
    dp[1][RED] = cost[1][RED];
    dp[1][GREEN] = cost[1][GREEN];
    dp[1][BLUE] = cost[1][BLUE];

    for (int i = 2; i <= N; i++) {
        // i번 집을 Red로 칠할 때
        dp[i][RED] = min(dp[i - 1][GREEN], dp[i - 1][BLUE]) + cost[i][RED];

		// i번 집을 Green로 칠할 때
        dp[i][GREEN] = min(dp[i - 1][RED], dp[i - 1][BLUE]) + cost[i][GREEN];

		// i번 집을 Blue로 칠할 때
        dp[i][BLUE] = min(dp[i - 1][RED], dp[i - 1][GREEN]) + cost[i][BLUE];
    }

    int result = min(dp[N][RED], dp[N][GREEN]);
    result = min(result, dp[N][BLUE]);

    printf("%d", result);
}

int main(void) {
    //(void)freopen("b1149.txt", "r", stdin);
    inputData();
    solve();

    return 0;
}

#endif
