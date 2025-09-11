/*
첫째 줄에 정수의 개수가 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2)
둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다.
(1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.

첫째 줄에 연결 요소의 개수를 출력한다.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N (1000+1)

int N;
int M;
int connect[MAX_N*MAX_N/2][2];
int visited[MAX_N];


void inputData(void) {
	N = 0;
	//(void)freopen("b11724.txt", "r", stdin);
	(void)scanf("%d", &N);
	M = 0;
	(void)scanf("%d", &M);

	for (int i = 1; i <= M; ++i) {
		(void)scanf("%d %d", connect[i], connect[i]+1);
	}
}

void printData(int (*ary)[2], int N) {
	for (int i = 1; i <= N; ++i) {
		printf("%d %d\n", ary[i][0], ary[i][1]);
	}
}

void DFS(int num) {
	//if (visited[num]) return;
	visited[num] = 1;

	for (int i = 1; i <= M; ++i) {
		if ((connect[i][0] == num) && !visited[connect[i][1]]) {
			DFS(connect[i][1]);
		}
		else if ((connect[i][1] == num) && !visited[connect[i][0]]) {
			DFS(connect[i][0]);
		}
	}
}

int checknext(int* v, int num) {
	for (int i = 1; i <= num; ++i) {
		if (!v[i]) {
			return i;
		}
	}
	return 0;
}


int main(void) {
	inputData();
	//printData(connect, M);

	int rst = 0;
	int next = 0;
	while (next = checknext(visited, N)) {
		DFS(next);
		++rst;
	}
	printf("%d", rst);
	return 0;
}
