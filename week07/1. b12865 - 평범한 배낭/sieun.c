#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 101
#define MAX_V 100001
int N, K;
int W[MAX_N], V[MAX_N];
int DP[MAX_N][MAX_V];
// DP[i][w] = i번째 물건까지 고려했을 때, 배낭 용량이 w일 때의 최대 가치

void inputData() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &W[i], &V[i]);
	}
}

int retmax(int a, int b) {
	return a > b ? a : b;
}

// i를 안 넣는 경우 DP[i-1][w]
// i를 넣는 경우 DP[i-1][w - W[i]] + V[i]
// 둘 중 큰 값을 취한다.
int solve() {
	for (int i = 1; i <= N; i++) {
		for (int w = 1; w <= K; w++) {
			if (w < W[i])
				DP[i][w] = DP[i - 1][w]; // 못 넣음
			else
				DP[i][w] = retmax(DP[i - 1][w], DP[i - 1][w - W[i]] + V[i]);
		}
	}
	return DP[N][K];
}

int main() {
	inputData();
	int result = solve();
	printf("%d", result);

	return 0;
}

#endif
