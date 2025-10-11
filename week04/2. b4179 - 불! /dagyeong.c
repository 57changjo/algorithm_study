// 2번 불
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX (1000+2)

enum { EMPTY = 1, FIRE = 2, WALL= 3 }; // . F #
int R, C;
int map[MAX][MAX];
int visitedJ[MAX][MAX];
int visitedF[MAX][MAX];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int sr, sc;

typedef struct node {
	int r;
	int c;
}Node;
Node QueueF[MAX * MAX];
Node QueueJ[MAX * MAX];
int frontF, rearF;
int frontJ, rearJ;

void inputData(void) {
	char temp[MAX] = { 0 };
	(void)scanf("%d %d", &R, &C);
	for (int i = 1; i <= R; ++i) {
		(void)scanf("%s", temp + 1);
		for (int j = 1; j <= C; ++j) {
			if (temp[j] == '.') map[i][j] = EMPTY;
			else if (temp[j] == 'F') map[i][j] = FIRE;
			else if (temp[j] == '#') map[i][j] = WALL;
			else if (temp[j] == 'J') { map[i][j] = EMPTY; sr = i, sc = j; }
		}
	}
}

void printData(void) {
	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int BFS(void) {
	Node currJ = { 0 };
	Node currF = { 0 };
	frontJ = rearJ = 0;
	frontF = rearF = 0;

	for (int i = 1; i <= R; ++i) {
		for (int j = 1; j <= C; ++j) {
			if (map[i][j] == FIRE) {
				QueueF[rearF++] = (Node){ i, j };
				visitedF[i][j] = 1;
			}
		}
	}
	
	while (frontF != rearF) {
		currF = QueueF[frontF++];
		int count = visitedF[currF.r][currF.c];
		for (int i = 0; i < 4; ++i) {
			int nr = currF.r + dr[i];
			int nc = currF.c + dc[i];
			if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
			if (map[nr][nc] == EMPTY && !(visitedF[nr][nc])) {
				QueueF[rearF++] = (Node){ nr, nc };
				visitedF[nr][nc] = count + 1;
			}
		}
	}

	QueueJ[rearJ++] = (Node){ sr, sc };
	visitedJ[sr][sc] = 1;

	while (frontJ != rearJ) {
		currJ = QueueJ[frontJ++];
		int time = visitedJ[currJ.r][currJ.c] + 1;
		for (int i = 0; i < 4; ++i) {
			int nr = currJ.r + dr[i];
			int nc = currJ.c + dc[i];
			if (nr < 1 || nr > R || nc < 1 || nc > C) return time - 1;
			if (map[nr][nc] == EMPTY && !(visitedJ[nr][nc])) {
				if (visitedF[nr][nc] && (visitedF[nr][nc] <= time)) continue;
				QueueJ[rearJ++] = (Node){ nr, nc };
				visitedJ[nr][nc] = time;
			}
		}
	}
	return -1; //impossible
}

int main(void) {
	(void)freopen("b4179.txt", "r", stdin);
	inputData();
	printData();

	int cnt = 0;
	cnt = BFS();
	if (cnt == -1) printf("IMPOSSIBLE");
	else printf("%d", cnt);

	return 0;
}
#endif
