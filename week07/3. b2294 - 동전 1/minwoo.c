#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COINS 101
#define MAX_K 10001

int coins[MAX_COINS];
int total[MAX_K];

int main(void) {

	int N, K;

	(void)scanf("%d %d", &N, &K);

	for(int i = 0; i < N; i++) {
		(void)scanf("%d", &coins[i]);
	}

	total[0] = 1;

	for(int i = 0; i < N; i++) {
		for (int j = coins[i]; j <= K; j++) {
			total[j] += total[j - coins[i]];
		}
	}

	printf("%d", total[K]);

	return 0;
}
#endif
