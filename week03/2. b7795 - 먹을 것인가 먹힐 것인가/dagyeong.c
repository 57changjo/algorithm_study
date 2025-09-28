// 2. 이진탐색
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))
#define MAX (20000)

int N, M;
int sizeA[MAX];
int sizeB[MAX];
int cnt;

int compInt(const void* ap, const void* bp) {
	int a = *(int*)ap;
	int b = *(int*)bp;
	return (a > b) - (a < b);
}

void inputData(void) {
	// 배열 초기화
	for (int i = 0; i < N; ++i) sizeA[i] = 0;
	for (int i = 0; i < M; ++i) sizeB[i] = 0;

	(void)scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", sizeA + i);
	}
	for (int i = 0; i < M; ++i) {
		(void)scanf("%d", sizeB + i);
	}
	qsort(sizeA, N, sizeof(sizeA[0]), compInt);
	qsort(sizeB, M, sizeof(sizeB[0]), compInt);
}

void printData(void) {
	printf("A: \n");
	for (int i = 0; i < N; ++i) {
		printf("%d ", sizeA[i]);
	}
	printf("\nB: \n");
	for (int i = 0; i < M; ++i) {
		printf("%d ", sizeB[i]);
	}
	printf("\n");

}
void BinarySearch(int num) { // 작은 것의 개수 sum
	int high = M - 1;
	int low = 0;
	int mid = -1;
	int reg = M;
	while (low <= high) {
		mid = (high + low) / 2;
		if (sizeB[mid] >= num) {
			reg = mid;
			high = mid - 1;
		}
		else { //sizeB[mid] < num
			low = mid + 1;
		}
	}
	cnt += reg;
}

int main(void) {

	int T = 0;
	//(void)freopen("b7795.txt", "r", stdin);
	(void)scanf("%d", &T);
	while (T--) {
		cnt = 0;
		inputData();
		//printData();
		for (int i = 0; i < N; i++) {
			BinarySearch(sizeA[i]);
			//printf("%d ", sizeA[i]);
		}
		printf("%d\n", cnt);
	}

	return 0;
}
#endif
