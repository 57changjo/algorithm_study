#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX (1000)

int N, x;
int ary[MAX][2];
int res1, res2, res3, res4;

void inputData(void) {
	(void)scanf("%d", &N);
	for (int i = 1; i < N; i++) {
		(void)scanf("%d %d", ary[i], ary[i]+1);
	}
	(void)scanf("%d", &x);
}

void findRoot(void) {
	int cnt = 0;
	int pid = x;
	while (pid != 1) {
		for(int i =1; i<N; ++i){
			if (ary[i][0] == pid) {
				pid = ary[i][1];
				cnt++;
				break;
			}
		}
	}
	res1 = cnt;
}

void findChilds(int L, int c) { //DFS
	for (int i = 1; i < N; ++i) {
		if (ary[i][1] == c) {
			res2++;
			findChilds(L + 1, ary[i][0]);
		}
	}
	if (L > res3) res3 = L;
	return;
}

int max;
void findChilds_2(int L, int p, int b) {
	for (int i = 1; i < N; ++i) {
		if (ary[i][1] == p && ary[i][0]!= b) {
			findChilds_2(L + 1, ary[i][0], b);
		}
	}
	if (L > res4) res4 = L;
	return;
}
void findDist(int L, int c) { //DFS
	for (int i = 1; i < N; ++i) {
		if (ary[i][0] == c) {
			findDist(L + 1, ary[i][1]);
			findChilds_2(L + 1, ary[i][1], c);
			break;
		}
	}
	return;
}

int main(void) {
	(void)freopen("j9659.txt", "r", stdin);
	inputData();
	findRoot();
	findChilds(0, x);
	findDist(0, x);
	if (res4 < res3) res4 = res3;
	printf("%d\n%d\n%d\n%d", res1, res2+1, res3, res4 );
}
#endif
