#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
���� : n���� ���� �ٸ� ���� ���� a1, a2, ..., an���� �̷���� ������ �ִ�. ai�� ���� 1���� ũ�ų� ����, 1000000���� �۰ų� ���� �ڿ����̴�. �ڿ��� x�� �־����� ��, ai + aj = x (1 �� i < j �� n)�� �����ϴ� (ai, aj)���� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է� : ù° �ٿ� ������ ũ�� n�� �־�����. ���� �ٿ��� ������ ���ԵǴ� ���� �־�����. ��° �ٿ��� x�� �־�����. (1 �� n �� 100000, 1 �� x �� 2000000)
��� : ������ ������ �����ϴ� ���� ������ ����Ѵ�.
*/

int n, x;
int a[100000];
int result;

int compare(const int* a, const int* b) {
	return *(int*)a - *(int*)b; // ��������
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

	for (int i = 0; a[i] <= (x / 2); i++) { // x/2 ���� �۰ų� ���� ��Ҹ� (x Ȧ�� ���)
		for (int k = n - 1; a[k] > (x / 2); k--) { // x/2 ���� ū ��Ҹ�
			if (a[i] + a[k] == x) result++;
		}
	}
	printf("%d\n", result);

	return 0;
}
#endif