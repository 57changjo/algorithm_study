#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#define MAX_N 1000

typedef enum _RGB {
	RED = 0,
	GREEN = 1,
	BLUE = 2
}RGB;

int Cost[MAX_N][3];
int house[MAX_N][3];

int N;

void inputdata() {
	(void)scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			(void)scanf("%d", &Cost[i][j]);
		}
	}
}

void printdata() {
	printf("%d\n", N);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d ", Cost[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int whatismin(int* ary, int size) {
	int min_n = INT_MAX;
	for (int i = 0; i < size; i++) {
		if (min_n > ary[i]) {
			min_n = ary[i];
		}
	}
	return min_n;
}

int solve() {

	for (int i = 1; i <=N; i++) {
		for (int color = RED; color <= BLUE; color++) {
			int color_1 = (color + 1) % 3;
			int color_2 = (color + 2) % 3;
			if (house[i - 1][color_1] < house[i -1][color_2]) {
				house[i][color] = house[i - 1][color_1] + Cost[i][color];
			}
			else {
				house[i][color] = house[i - 1][color_2] + Cost[i][color];
			}
		}
	}

	return whatismin(house[N], 3);
	
}

int main() {
	(void)freopen("prob2.txt", "r", stdin);
	inputdata();
	printf("%d\n", solve());
	return 0;
}
