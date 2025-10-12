#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define MAX_N (500000+2)

int card[MAX_N];
int num[MAX_N];
int ans[MAX_N];

int M, N;

void inputdata() {
	(void)scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		(void)scanf("%d", card + i);
	}
	(void)scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		(void)scanf("%d", num + i);
	}
}

void change(int *a, int *b) {
	int temp = 0;
	temp = *a;
	*a = *b;
	*b = temp;
}

int comp(const void* a, const void* b) {
	int* num1 = (int*)a;
	int* num2 = (int*)b;

	if (*num1 > *num2) 
		return 1;
	else if (*num1 < *num2) 
		return -1;
	else
		return 0;
}




void printary(int* ary, int len) {
	for (int i = 0; i < len; i++) {
		printf("%d ", ary[i]);
	}
	printf("\n");
}


int lower_bound(int x, int* ary, int size) {
	int start = 0;
	int end = size; // 배열의 끝 바로 다음을 가리킴
	int result = size;

	while (start < end) {
		int mid = (start + end) / 2;
		if (ary[mid] >= x) {
			result = mid;
			end = mid;    // 같거나 크다면, 더 왼쪽에 있을 수 있으므로 end를 mid로 설정
		}
		else {
			start = mid + 1; // 작다면, 오른쪽으로 이동
		}
	}
	return result;
}

int upper_bound(int x, int* ary, int size) {
	int start = 0;
	int end = size;
	int result = size;

	while (start < end) {
		int mid = (start + end) / 2;
		if (ary[mid] > x) {
			result = mid;
			end = mid;    // 크다면, 더 왼쪽에 있을 수 있으므로 end를 mid로 설정
		}
		else {
			start = mid + 1; // 작거나 같다면, 오른쪽으로 이동
		}
	}
	return result;
}

int bnsearch_count(int x, int* ary, int size) {
	int low = lower_bound(x, ary, size);
	int high = upper_bound(x, ary, size);

	return high - low;
}


void solve() {
	for (int i = 0; i < M; i++) {
		ans[i] = bnsearch_count(num[i], card, N);	
	}
}

int main(void) {
	(void)freopen("prob3.txt", "r", stdin);
	inputdata();
	qsort((void*)card, N, sizeof(int), comp);
	solve();
	printary(ans, M);
	return 0;
}
