#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N 1000000
#if 00
int n;
int num[MAX_N];
int x;

void input_Data() {
	(void)freopen("sum.txt", "r", stdin);
	(void)scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		(void)scanf("%d", &num[i]);
	}
	(void)scanf("%d", &x);
}


void print_Data() {
	for (int i = 0; i < n; ++i) {
		printf("%d ", num[i]);
	}
	printf("\n");
}

int sum() {
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i+1; j < n; ++j) {
			if (num[i] + num[j] == x) {
				++cnt;
			}
		}
	}
	return cnt;
}
int main() {
	input_Data();
	print_Data();
	printf("%d", sum());
	return 0;
}

#endif