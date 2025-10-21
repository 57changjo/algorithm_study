#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 101
#define MAX_K 10000
int N, K;
int coin[MAX_N];
int DP[MAX_K];
// DP[K]: 금액 K를 만들 수 있는 경우의 수

void inputData() {
	scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &coin[i]);
	}
}

int solve() {
	// init
	DP[0] = 1; // 0개의 동전으로 0원을 만드는 경우의 수 1가지

	for (int i = 1; i <= N; i++) {
		for (int j = coin[i]; j <= K; j++) {
			DP[j] += DP[j - coin[i]];
		}
	}
	return DP[K];
}

int main() {
	inputData();
	int result = solve();
	printf("%d", result);

	return 0;
}
#endif
