// 시간초과
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N (100+1)
#define MAX_K (100000+1)
enum { weight = 0, value = 1 };

int N, K;
int items[MAX_N][2]; // 무게, 가치 저장
int max_value[MAX_K]; // 무게별 최대 가치

int comp(const void* ap, const void* bp) {
	int *arrA = (int*)ap;
	int *arrB = (int*)bp;
	return (arrA[weight] > arrB[weight]) - (arrA[weight] < arrB[weight]);
}

void inputData(void) {
	(void)scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; ++i) {
		(void)scanf("%d %d", items[i] + weight, items[i] + value);
	}
	qsort(items + 1, N, sizeof(items[0]), comp);
}

void printData(void) {
	for (int i = 1; i <= N; ++i) {
		printf("%d %d\n", items[i][weight], items[i][value]);
	}
}

void DFS(int start, int total_w, int total_v) {
	for (int i = start; i <= N; ++i) {
		int sum_w = total_w + items[i][weight];
		int sum_v = total_v + items[i][value];
		if (sum_w > K) return;
		if (max_value[sum_w] < sum_v) max_value[sum_w] = sum_v;
		DFS(i + 1, sum_w, sum_v);
	}
}

int findMax(void) {
	int max = 0;
	for (int i = 1; i <= K; ++i) {
		if (max_value[i] > max) max = max_value[i];
	}
	return max;
}

int main(void) {
	//(void)freopen("b12865.txt", "r", stdin);
	inputData();
	//printData();

	DFS(1, 0, 0);
	printf("%d", findMax());

	return 0;
}

#endif
