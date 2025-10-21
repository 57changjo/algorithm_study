#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1001
int N;
int cost[MAX_N][3];
int DP[MAX_N][3];
// DP[i][c] = i번째 집을 색상 c로 칠했을 때, i번째 집까지의 최소 비용

void inputData() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
}

int retmin(int a, int b) {
	return a < b ? a : b;
}

int solve() {
	// init
	DP[1][0] = cost[1][0];
	DP[1][1] = cost[1][1];
	DP[1][2] = cost[1][2];

	for (int i = 2; i <= N; i++) {
		DP[i][0] = retmin(DP[i - 1][1], DP[i - 1][2]) + cost[i][0];
		DP[i][1] = retmin(DP[i - 1][0], DP[i - 1][2]) + cost[i][1];
		DP[i][2] = retmin(DP[i - 1][0], DP[i - 1][1]) + cost[i][2];
	}

	return retmin(retmin(DP[N][0], DP[N][1]), DP[N][2]);
}

int main() {
	inputData();
	int result = solve();
	printf("%d", result);

	return 0;
}
#endif
