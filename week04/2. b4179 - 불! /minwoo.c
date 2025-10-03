#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 1000

typedef struct {

	int r, c, t;

}Node;

Node Queue[SIZE * SIZE];
char maze[SIZE][SIZE];
int fire_time[SIZE][SIZE];
int jihun_time[SIZE][SIZE];
int R, C;
int front = 0;
int rear = 0;

void fire_bfs() {

	front = 0;
	rear = 0;

	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			if (maze[r][c] == 'F') {
				Queue[rear++] = (Node){ r,c, 0 };
				fire_time[r][c] = 0;
			}
		}
	}

	while (front < rear) {

		Node cur = Queue[front++];

		for (int d = 0; d < 4; d++) {

			int nr = cur.r + dr[d];
			int nc = cur.c + dc[d];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

			if (maze[nr][nc] == '#') continue;

			if (fire_time[nr][nc] != -1) continue;

			fire_time[nr][nc] = cur.t + 1;
			Queue[rear++] = (Node){ nr, nc, cur.t + 1 };
		}
	}
}

void jihun_bfs(int start_r, int start_c) {

	int dr[4] = { -1, 1, 0, 0 };
	int dc[4] = { 0, 0, -1, 1 };

	front = 0;
	rear = 0;
	Queue[rear++] = (Node){ start_r, start_c, 0 };
	jihun_time[start_r][start_c] = 0;

	while (front < rear) {
		Node cur = Queue[front++];

		if (cur.r == 0 || cur.r == R - 1 || cur.c == 0 || cur.c == C - 1) {
			printf("%d\n", cur.t + 1);
			return;
		}

		for (int d = 0; d < 4; d++) {

			int nr = cur.r + dr[d];
			int nc = cur.c + dc[d];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
			if (maze[nr][nc] == '#') continue;
			if (jihun_time[nr][nc] != -1) continue;
			if (fire_time[nr][nc] != -1 && fire_time[nr][nc] <= cur.t + 1) continue;

			jihun_time[nr][nc] = cur.t + 1;
			Queue[rear++] = (Node){ nr, nc, cur.t + 1 };
		}
	}

	printf("IMPOSSIBLE\n");
}

#if 0
int main(void) {

	(void)freopen("b4179.txt", "r", stdin);

	(void)scanf("%d %d", &R, &C);

	int start_r, start_c;

	for (int i = 0; i < R; i++) {
		(void)scanf("%s", &maze[i]);

		for (int j = 0; j < C; j++) {
			if (maze[i][j] == 'J') {
				start_r = i;
				start_c = j;
			}
		}
	}

	for (int r = 0; r < R; r++) {
		for (int c = 0; c < C; c++) {
			fire_time[r][c] = -1;
			jihun_time[r][c] = -1;
		}
	}

	fire_bfs();
	jihun_bfs(start_r, start_c);

	return 0;
}
#endif
