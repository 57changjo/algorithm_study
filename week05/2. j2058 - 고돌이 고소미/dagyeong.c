// 2번 고돌이 고소미
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX (25+2)

int N;
int Dr, Dc, DHr, DHc;
int Sr, Sc, SHr, SHc;
int map[MAX][MAX];
int nr[9] = { -1, 1, 0, 0, 1, 1, -1, -1, 0 };
int nc[9] = { 0, 0, -1, 1, 1, -1, 1, -1, 0 };

typedef struct _node {
	int dr, dc, sr, sc, cnt;
}node_t;
node_t Queue[MAX * MAX * MAX * MAX];
int visited[MAX][MAX][MAX][MAX];
int front, rear;

void inputData(void) {
	(void)scanf("%d", &N);
	(void)scanf("%d %d %d %d", &Dr, &Dc, &DHr, &DHc);
	(void)scanf("%d %d %d %d", &Sr, &Sc, &SHr, &SHc);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			(void)scanf("%d", map[i] + j);
		}
	}
}

int BFS(void) {
	node_t curr = { 0 };
	front = rear = 0;

	Queue[rear++] = (node_t){ Dr, Dc, Sr, Sc, 0 };
	visited[Dr][Dc][Sr][Sc] = 1;

	while (front != rear) {
		curr = Queue[front++];
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (i == 8 && j == 8) continue;
				int nDr = curr.dr + nr[i];
				int nDc = curr.dc + nc[i];
				int nSr = curr.sr + nr[j];
				int nSc = curr.sc + nc[j];
				if (visited[nDr][nDc][nSr][nSc]) continue;
				if (nDr == DHr && nDc == DHc && nSr == SHr && nSc == SHc) return curr.cnt + 1;
				if (nDr < 1 || nDr > N || nDc < 1 || nDc > N || nSr < 1 || nSr > N || nSc < 1 || nSc > N) continue;
				if (map[nDr][nDc] || map[nSr][nSc]) continue;
				if ((abs(nDr - nSr) <= 1) && (abs(nDc - nSc) <= 1)) continue;
				Queue[rear++] = (node_t){ nDr, nDc, nSr, nSc, curr.cnt + 1 };
				visited[nDr][nDc][nSr][nSc] = 1;
				//printf("%d %d %d %d %d\n", nDr, nDc, nSr, nSc, curr.cnt + 1);
			}
		}
	}
	return 0;
}

void printData(void) {
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= N; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	//(void)freopen("j2058.txt", "r", stdin);
	inputData();
	//printData();
	printf("%d\n", BFS());
	return 0;
}
#endif
