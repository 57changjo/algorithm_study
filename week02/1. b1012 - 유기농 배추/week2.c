
// b 1012
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N (50+2)
int T, M, N, K; // tc 개수, 가로, 세로 길이, 배추 개수
int map[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
typedef struct _node {
	int r, c;
}node_t;
node_t Queue[MAX_N * MAX_N];
int front, rear;

void inputData() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < K; i++) {
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		map[b+1][a+1] = 1;
	}
}

void init() {
	for (int i = 0; i < N+2; i++) {
		for (int j = 0; j < M+2; j++) {
			vis[i][j] = 0;
			map[i][j] = 0;
		}
	}
}

void DFS(int sR, int sC) {
	vis[sR][sC] = 1;
	for (int i = 0; i < 4; i++) {
		int nr = sR + dr[i];
		int nc = sC + dc[i];
		if (map[nr][nc] && !vis[nr][nc]) {
			DFS(nr, nc);
		}
	}

}

void BFS(int sR, int sC) {
	front = rear = 0;
	node_t curr = { 0 };
	Queue[rear++] = (node_t){ sR, sC };

	while (front != rear) {
		curr = Queue[front++];
		for (int i = 0; i < 4; i++) {
			int nr = curr.r + dr[i];
			int nc = curr.c + dc[i];
			if (map[nr][nc] && !vis[nr][nc]) {
				vis[nr][nc] = 1;
				Queue[rear++] = (node_t){ nr, nc };
			}
		}
	}
}

int main() {
	freopen("b1012.txt", "r", stdin);
	scanf("%d", &T);
	
	while (T--) {
		init();
		inputData();
		int cnt = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				if (map[i][j] && !vis[i][j]) {
					DFS(i, j);
					cnt++;
				}
			}
		}
		printf("%d\n", cnt);
	}

	return 0;
}

#endif
