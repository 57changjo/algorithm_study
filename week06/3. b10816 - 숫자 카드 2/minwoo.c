#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N, M;
int sangun_cards[500001];
int check_sangun_cards[500001];

int compare(const void* a, const void* b) {
	
	return *(int*)a - *(int*)b;
}

int lower(int arry[], int size, int target) {

	int left = 0;
	int right = size;

	while (left < right) {

		int mid = (left + right) / 2;

		if (arry[mid] < target) {
			left = mid + 1;
		}
		else right = mid;
	}
	return left;
}

int upper(int arry[], int size, int target) {

	int left = 0;
	int right = size;

	while (left < right) {

		int mid = (left + right) / 2;

		if (arry[mid] <= target) {
			left = mid + 1;
		}
		else right = mid;
	}
	return left;
}

int main(void) {

	(void)scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		(void)scanf("%d", &sangun_cards[i]);
	}

	(void)scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		(void)scanf("%d", &check_sangun_cards[i]);
	}

	qsort(sangun_cards, N, sizeof(int), compare);

	for (int i = 0; i < M; i++) {
		int checking_number = check_sangun_cards[i];
		int answer = upper(sangun_cards, N, checking_number) - lower(sangun_cards, N, checking_number);

		printf("%d ", answer);
	}
	return 0;
}
#endif
