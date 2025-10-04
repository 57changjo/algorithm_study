#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#define MAX_R (1000+1)
#define MAX_C (1000+1)

typedef struct _node {
	int r, c;
}node_t;
node_t Q[MAX_R * MAX_C];
node_t F[MAX_R * MAX_C];
int front, rear;

int R, C;

char map[MAX_R][MAX_C];
int fire[MAX_R][MAX_C];
int visited[MAX_R][MAX_C];

void inputdata(void) {
	(void)scanf("%d %d", &R, &C);
	for (int i = 0; i < R; ++i) {
		(void)scanf("%s", map[i]);
	}
}

void printdata(char (*ary)[MAX_R]) {
	printf("%d %d", R, C);
	printf("\n");
	for (int i = 0; i < R; ++i) {
		printf("%s\n", ary[i]);
	}
	printf("\n");
}

int dr[4] = { 1,-1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
void BFS_fire() {
	front = rear = 0;
	node_t current;
	int nr, nc;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == 'F') {
				F[rear++] = (node_t){ i, j };
				fire[i][j] = 1;														//시작점들 초기화
			}
		}
	}
	while (front != rear) {
		current = F[front++];
		for (int i = 0; i < 4; i++) {
			nr = current.r + dr[i];
			nc = current.c + dc[i];									// 옆이 불타고 있으면 확산 필요 X (무한루프 가능성)
			if (nr >= R || nr < 0 || nc < 0 || nc >= C) continue;
			if (fire[nr][nc]) continue;
			if (map[nr][nc] == '#' || map[nr][nc] == 'F') continue;
			fire[nr][nc] = fire[current.r][current.c] + 1;
			F[rear++] = (node_t){ nr, nc };
		}
	}
}

int BFS(void) {
	front = rear = 0;
	node_t current;
	int nr, nc;
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			if (map[i][j] == 'J') {
				Q[rear++] = (node_t){ i, j };
				visited[i][j] = 1;
			}
		}
	}
	while (front != rear) {
		current = Q[front++];
		for (int i = 0; i < 4; i++) {
			nr = current.r + dr[i];
			nc = current.c + dc[i];
			if (nr >= R || nr < 0 || nc < 0 || nc >= C) return visited[current.r][current.c];
			if (visited[nr][nc] || map[nr][nc] == '#' || map[nr][nc] == 'F') continue;
			if (fire[nr][nc] && fire[nr][nc] <= visited[current.r][current.c] + 1) continue;
			visited[nr][nc] = visited[current.r][current.c] + 1;
			Q[rear++] = (node_t){ nr, nc };
		}
	}
	return -1;
}

void printdata2(int (*ary)[MAX_R]) {
	for (int i = 0; i < R; ++i) {
		for (int j = 0; j < C; ++j) {
			printf("%d", ary[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void) {
	//(void)freopen("prob2.txt", "r", stdin);
	inputdata();
	//printdata(map);
	BFS_fire();
	//printdata2(fire);
	int result = BFS();
	if (result == -1) { printf("IMPOSSIBLE\n"); }
	else printf("%d\n", result);
	//printdata2(visited);
	return 0;
}
#endif
