#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
문제 : n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 1000000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

입력 : 첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)
출력 : 문제의 조건을 만족하는 쌍의 개수를 출력한다.
*/

int n, x;
int a[100000];
int result;

int compare(const int* a, const int* b) {
	return *(int*)a - *(int*)b; // 오름차순
}

inputData() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d\n", &a[i]);
	}
	scanf("%d", &x);
}

int main() {
	//(void)freopen("b3273.txt", "r", stdin);
	inputData();

	qsort(a, n, sizeof(a[0]), compare);

	for (int i = 0; a[i] <= (x / 2); i++) { // x/2 보다 작거나 같은 요소만 (x 홀수 고려)
		for (int k = n - 1; a[k] > (x / 2); k--) { // x/2 보다 큰 요소만
			if (a[i] + a[k] == x) result++;
		}
	}
	printf("%d\n", result);

	return 0;
}
#endif