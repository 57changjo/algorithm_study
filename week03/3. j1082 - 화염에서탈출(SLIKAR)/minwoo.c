#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 52

char map[SIZE][SIZE];
char input[SIZE];
int R, C;
int fire[SIZE][SIZE];
int dr[4] = { -1, 1, 0,0 };
int dc[4] = { 0, 0, -1, 1 };

typedef struct {

	int r, c;
} Node;

Node Queue[SIZE * SIZE];
int front, rear;

void BFS(int R, int C) {

	front = 0;
	rear = 0;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			fire[i][j] = 9999;
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == '*') {
				fire[i][j] = 0;
				Queue[rear++] = (Node){ i,j };
			}
		}
	}

	while (front < rear) {
		Node cur = Queue[front++];
		int r = cur.r;
		int c = cur.c;

		for (int i = 0; i < 4; i++) {
			int nr = r + dr[i];
			int nc = c + dc[i];

			if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

			if (map[nr][nc] == 'X' || map[nr][nc] == 'D') continue;

			if (fire[nr][nc] > fire[r][c] + 1) {
				fire[nr][nc] = fire[r][c] + 1;
				Queue[rear++] = (Node){ nr,nc };
			}
		}
	}

}

#if 0
// j1082
int main(void) {

	(void)freopen("j1082.txt", "r", stdin);

	(void)scanf("%d %d", &R, &C);

	for (int i = 0; i < R; i++) {
		(void)scanf("%s", input);
		for (int j = 0; j < C; j++) {
			map[i][j] = input[j];
		}
	}

	//for (int i = 0; i < R; i++) {
	//	for (int j = 0; j < C; j++) {
	//		printf("%c", map[i][j]);
	//	}
	//	printf("\n");
	//}

	BFS(R, C);

	return 0;
}
#endif
