#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 20
int n, m;
int open1, open2;
int seq[MAX];

void inputData(void) {
	scanf("%d", &n);
	scanf("%d %d", &open1, &open2);
	scanf("%d", &m);

	for (int i = 0; i < m; i++)
		scanf("%d", &seq[i]);
}

int min_val(int a, int b) {
	return a < b ? a : b;
}

int DFS(int idx, int open1, int open2) {
	if (idx == m) return 0; // 완료

	int target = seq[idx];
	int move1 = abs(open1 - target);
	int move2 = abs(open2 - target);

	// 두 가지 중 최솟값 선택
	int ret = min_val(
		move1 + DFS(idx + 1, target, open2),
		move2 + DFS(idx + 1, open1, target)
	);

	return ret;
}

int main() {
	inputData();

	int ans = DFS(0, open1, open2);
	printf("%d\n", ans);

	return 0;
}

#endif
