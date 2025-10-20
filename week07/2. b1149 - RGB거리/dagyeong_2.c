#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#define MAX_N (1000+1)
enum { red = 0, green = 1, blue = 2 };

int N;
int cost_RGB[MAX_N][3];

int min_cost = INT_MAX;
int min_mem[MAX_N][3];

void inputData(void) {
	(void)scanf("%d", &N);
	for (int i = 1; i <= N; ++i){
		(void)scanf("%d %d %d", cost_RGB[i] + red, cost_RGB[i] + green, cost_RGB[i] + blue);
	}
}

void printData(void) {
	for (int i = 1; i <= N; ++i) {
		printf("%d %d %d\n", cost_RGB[i][red], cost_RGB[i][green], cost_RGB[i][blue]);
	}
}

void DFS(int L, int rgb, int sum) {
	int sumCost = sum + cost_RGB[L][rgb];
	//printf("%d %d %d\n", L, rgb, sumCost);
    
	if (sumCost >= min_mem[L][rgb]) return;
	min_mem[L][rgb] = sumCost; //sumCost < min_mem 일때
	if (L >= N) return;

	DFS(L + 1, (rgb + 1) % 3, sumCost);
	DFS(L + 1, (rgb + 2) % 3, sumCost);
}

int main(void) {
	//(void)freopen("b1149.txt", "r", stdin);

	inputData();
	//printData();
    
    /* min_mem 초기화 */
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			min_mem[i][j] = INT_MAX;
		}
	}

	DFS(1, red, 0);
	DFS(1, green, 0);
	DFS(1, blue, 0);
    
    /* 최솟값 찾기 */
	int min = INT_MAX;
	for (int i = 0; i < 3; ++i) {
		if (min_mem[N][i] < min) min = min_mem[N][i];
	}
	printf("%d\n", min);

	return 0;
}
#endif
