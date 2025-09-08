#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {

	int A = *(const int*)a;
	int B = *(const int*)b;

	return (A > B) - (A < B); // asc
}

int main(void) {

	// 수열의 크기 n
	// 수열 안에 있는 값들
	// x (수열 값 ai + aj = x)

	int n = 0;
	int temp = 0;
	int list[100000];
	int x = 0;
	int count = 0;

	(void)scanf("%d", &n);

	for (int i = 0; i < n; i++) {

		(void)scanf("%d", &temp);
		list[i] = temp;
	}

	(void)scanf("%d", &x);

	int size = sizeof(list) / sizeof(list[0]);

	qsort(list, n, sizeof(int), compare);

	int left = 0;
	int right = n - 1;

	while (left < right) {

		int sum = list[left] + list[right];

		if (sum == x) {

			count++;
			left++;
			right--;
		}

		else if (sum < x) {

			left++;
		}

		else {

			right--;
		}
	}

	printf("%d", count);

	return 0;
}
