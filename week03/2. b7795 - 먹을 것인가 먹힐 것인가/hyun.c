#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#define MAX_N 20000
#define MAX_M 20000

int N;
int M;
int T;
int ary_A[MAX_N];
int ary_B[MAX_M];


void inputdata() {
	(void)scanf("%d %d", &N, &M);
	for (int i = 0; i < N; ++i) {
		(void)scanf("%d", ary_A+i);
	}
	for (int i = 0; i < M; ++i) {
		(void)scanf("%d", ary_B + i);
	}
}

void printdata() {
	printf("%d %d", N, M);
	printf("\n");
	for (int i = 0; i < N; ++i) {
		printf("%d ", ary_A[i]);
	}
	printf("\n");
	for (int i = 0; i < M; ++i) {
		printf("%d ", ary_B[i]);
	}
	printf("\n");
}

int BinarySearch_Upper(int num, int* ary, int low, int high) {
	int mid;
	int ret = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		if (ary[mid] == num) return mid;
		if (ary[mid] < num) {
			ret = mid;
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ret + 1;
}


int solve(int cnt) {
	for (int i = 0; i < N; i++) {
		//printf("%d\n", BinarySearch_Upper(ary_A[i], ary_B, 0, M));
		cnt = cnt + BinarySearch_Upper(ary_A[i], ary_B, 0, M-1);
	}
	return cnt;
}

void swap(int* a, int* b) {
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort_Arr(int* arr) {								
	for (int i = 0; i < M; ++i) {
		for (int j = i + 1; j < M; ++j) {
			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}
}

int main() {
	int cnt = 0;
	(void)freopen("prob1.txt", "r", stdin);
	(void)scanf("%d", &T);
	while (T--) {
		inputdata();
		sort_Arr(ary_B);
		printf("%d\n", solve(cnt));
	}
}
#endif
