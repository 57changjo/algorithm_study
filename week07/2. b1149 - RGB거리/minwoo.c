#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_HOUSES 1001
int costs[MAX_HOUSES][3];

int find_min(int a, int b) {

	return (a < b) ? a : b;
}

enum COLORS {

	R = 0,
	G = 1,
	B = 2

};

int main(void) {

	int N;

	(void)scanf("%d", &N);

	for(int i = 1; i <= N; i++) {
		(void)scanf("%d %d %d", &costs[i][R], &costs[i][G], &costs[i][B]);
	}

	for (int i = 2; i <= N; i++) {
		costs[i][R] += find_min(costs[i - 1][B], costs[i - 1][G]);
		costs[i][G] += find_min(costs[i - 1][R], costs[i - 1][B]);
		costs[i][B] += find_min(costs[i - 1][R], costs[i - 1][G]);
	}

	printf("%d", find_min(find_min(costs[N][R], costs[N][G]), costs[N][B]));

	return 0;
}
#endif
