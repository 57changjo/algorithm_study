#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_C (100+1)

int N;
int coN;
int cnt;
int connect[MAX_C*MAX_C][2];
int visited[MAX_C];

void inputData(void) {
	N = 0;
	//(void)freopen("b2602.txt", "r", stdin);
	(void)scanf("%d", &N);
	coN = 0;
	(void)scanf("%d", &coN);

	for (int i = 1; i <= coN; ++i) {
		(void)scanf("%d %d", connect[i], connect[i]+1);
	}
}

//void printData(int (*ary)[2], int N) {
//	for (int i = 1; i <= N; ++i) {
//		printf("%d %d\n", ary[i][0], ary[i][1]);
//	}
//}

void DFS(int virused) {
	visited[virused] = 1;
	for (int i = 1; i <= coN; ++i) {
		if ((connect[i][0] == virused) && !visited[connect[i][1]]) {
			++cnt;
			DFS(connect[i][1]);
		}
		else if ((connect[i][1] == virused) && !visited[connect[i][0]]) {
			++cnt;
			DFS(connect[i][0]);
		}
	}
}

int main(void) {
	inputData();
	//printData(connect, coN);

	cnt = 0;
	int virused = 1;
	DFS(virused);

	printf("%d", cnt);
	return 0;
}
