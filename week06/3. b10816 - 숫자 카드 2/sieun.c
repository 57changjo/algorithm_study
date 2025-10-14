#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 500000

int M, N;
typedef long long ll;
ll n[MAX_N], m[MAX_N];

void inputData() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &n[i]);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &m[i]);
	}
}

int lower_bound(ll* arr, int size, ll key) {
	int low = 0;
	int high = size;

	while (low < high) {
		int mid = (low + high) / 2;

		if (arr[mid] >= key)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

int upper_bound(ll* arr, int size, ll key) {
	int low = 0;
	int high = size;

	while (low < high) {
		int mid = (low + high) / 2;

		if (arr[mid] > key)
			high = mid;
		else
			low = mid + 1;
	}
	return high;
}

int compare(const void* a, const void* b) {
	ll x = *(ll*)a;
	ll y = *(ll*)b;
	return (x > y) - (x < y);
}

void outputData() {
	for (int i = 0; i < M; i++) {
		int result = upper_bound(n, N, m[i]) - lower_bound(n, N, m[i]);
		printf("%d ", result);
	}
}
int main() {
	freopen("b10816.txt", "r", stdin);
	inputData();
	qsort(n, N, sizeof(n[0]), compare);
	outputData();

	return 0;
}

#endif
