// 1번 나무자르기
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 1000000

int M, N;
int trees[MAX_N];

int compInt(const void* ap, const void* bp) {
	int a = *(int*)ap;
	int b = *(int*)bp;
	return (a > b) - (a < b); //오름차순
}

void inputData(void) {
	(void)scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", trees + i);
	}
	qsort(trees, N, sizeof(trees[0]), compInt);
}

void printData(void) {
	for (int i = 0; i < N; ++i) {
		printf("%d ", trees[i]);
	}
	printf("\n");
}

int binarySearch(void) {
	int low = 0;
	int high = trees[N - 1];
	int mid = 0;
	int ret = 0;

	while (low <= high) {
		mid = (low + high) / 2;
		long long sum = 0; // sum의 type 변경
		for (int i = 0; i < N; ++i) {
			if (trees[i] > mid) {
				sum += (trees[i] - mid);
			}
		}
		if (sum > M) {
			low = mid + 1;
			ret = mid;
		}
		else if (sum == M) {
			return mid;
		}
		else { // sum < M
			high = mid - 1;
		}
	}
	return ret;
}

int main(void) {
	//(void)freopen("b2805.txt", "r", stdin);
	inputData();
	//printData();

	printf("%d", binarySearch());

	return 0;
}
#endif
