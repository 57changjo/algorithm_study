#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N (100+2)
int N, M; // 세로, 가로
int map[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
typedef struct _node {
	int r, c;
}node_t;
node_t Queue[MAX_N * MAX_N];
int front, rear;

inputData() {
	scanf("%d %d", &N, &M);
	char temp[MAX_N];
	for (int i = 1; i <= N; i++) {
		scanf("%s", temp + 1);
		for (int j = 1; j <= M; j++) {
			if (temp[j] == '0') map[i][j] = 0;
			else map[i][j] = 1;
		}
	}
}

printData() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int BFS_miroh() {
	front = rear = 0;
	node_t curr = { 0 };
	Queue[rear++] = (node_t){ 1, 1 };
	vis[1][1] = 1;

	while (front != rear) {
		curr = Queue[front++];
		for (int i = 0; i < 4; i++) {
			int nr = curr.r + dr[i];
			int nc = curr.c + dc[i];
			if (map[nr][nc] && !vis[nr][nc]) {
				vis[nr][nc] = vis[curr.r][curr.c] + 1;
				Queue[rear++] = (node_t){ nr, nc };
			}
		}
	}
	return vis[N][M];
}

int main() {
	//freopen("b2178.txt", "r", stdin);
	inputData();
	printf("%d\n", BFS_miroh());
	return 0;
}
#endif
