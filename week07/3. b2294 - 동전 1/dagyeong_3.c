//시간초과
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_n (100+1)

int n, k;
int coins[MAX_n];
int count;

int comp(const void* ap, const void* bp) {
	int a = *(int*)ap;
	int b = *(int*)bp;
	return (a > b) - (a < b);
}

void inputData(void) {
	(void)scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; ++i) {
		(void)scanf("%d", coins + i);
	}
	qsort(coins + 1, n, sizeof(coins[0]), comp);
}

void printData(void) {
	for (int i = 1; i <= n; ++i) {
		printf("%d\n", coins[i]);
	}
}

void dfs(int k_, int start) { // 10, 1
	if (k_ < 0) return;
	if (k_ == 0) {
		count++;
		//printf("count 갱신:  %d\n", count);
		return;
	}
	for(int i = start; i <= n; ++i) {
		//printf("dfs(%d, %d) 수행\n", k_ - coins[i], i);
		dfs(k_ - coins[i], i);
	}
}

int main(void) {
	//(void)freopen("b2293.txt", "r", stdin);
	inputData();
	//printData();

	/*for (int i = 1; i <= n; ++i) {
		printf("i = %d 시작\n", i);
		dfs(k, i);
	}*/
	dfs(k, 1);
	printf("%d", count);

	return 0;
}

#endif
