#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000000

int Trees[SIZE];
int T = 2;

// 나무 수
int N;
// 가져가려는 나무 높이
int M;

// 가장 높은 나무
int tallest_tree;

int find_h(int* ary, int N, int M, int tallest) {

	int low = 0;
	int high = tallest;
	int answer = 0;

	while (low <= high) {

		// 절단기 높이
		int mid = (low + high) / 2;
		long long total = 0;

		for (int i = 0; i < N; i++) {
			if (ary[i] > mid) {
				total += (ary[i] - mid);
			}
		}

		// 일단 지금 mid 높이로 M 은 가져갈 수 있다
		if (total >= M) {
			answer = mid;
			low = mid + 1;
		}

		// 현재 mid 높이론 M 만큼 못 가져가니깐 high 올려
		else if (total < M) {
			high = mid - 1;
		}
	}

	return answer;
}

#if 0
// b2850
int main(void) {

	//(void)freopen("b2850.txt", "r", stdin);

	(void)scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		(void)scanf("%d", &Trees[i]);
	}

	tallest_tree = Trees[0];

	for (int i = 1; i < N; i++) {
		if (tallest_tree < Trees[i]) {
			tallest_tree = Trees[i];
		}
	}

	printf("%d", find_h(Trees, N, M, tallest_tree));

	return 0;
}
#endif
