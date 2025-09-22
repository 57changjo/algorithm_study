#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20002

int T;
int A_count, B_count;
int A_temp, B_temp;
int A_species[MAX];
int B_species[MAX];

int compare(const void* a, const void* b) {

	if (*(int*)a > *(int*)b) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else return 0;

}

int binary_s(int ary[], int size, int A) {

	int left = 0;
	int right = size;

	while (left < right) {
		int mid = (left + right) / 2;

		if (ary[mid] < A) {
			left = mid + 1;
		}

		else {
			right = mid;
		}
	}
	return left;
}

#if 0
// b7795
int main(void) {

	(void)freopen("b7795.txt", "r", stdin);
	(void)scanf("%d", &T);

	while (T--) {

		(void)scanf("%d %d", &A_count, &B_count);

		for (int i = 0; i < A_count; i++) {
			(void)scanf("%d", &A_temp);
			A_species[i] = A_temp;
		}

		for (int j = 0; j < B_count; j++) {
			(void)scanf("%d", &B_temp);
			B_species[j] = B_temp;
		}

		qsort(A_species, A_count, sizeof(int), compare);
		qsort(B_species, B_count, sizeof(int), compare);

		int count = 0;

		for (int i = 0; i < A_count; i++) {
			count += binary_s(B_species, B_count, A_species[i]);
		}

		printf("%d\n", count);
	}

	return 0;
}
#endif
