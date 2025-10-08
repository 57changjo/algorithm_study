#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 30

#if 0
int map[SIZE][SIZE];
int godori_gasi[SIZE][SIZE];
int gosuni_gasi[SIZE][SIZE];
int visited[SIZE][SIZE];

int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

typedef struct {
	int r, c, t;
} Node;

Node Queue[SIZE * SIZE];
int front, rear;

int BFS_godori(int start_r, int start_c, int finish_r, int finish_c, int gasi_map[SIZE][SIZE], int N) {

	front = 0;
	rear = 0;

	Queue[rear++] = (Node){ start_r, start_c, 0 };
	visited[start_r][start_c] = 1;

	while (front < rear) {

		Node cur = Queue[front++];

		if (cur.r == finish_r && cur.c == finish_c) {
			return cur.t;
		}

		for (int i = 0; i < 8; i++) {
			int nr = cur.r + dr[i];
			int nc = cur.c + dc[i];

			if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
			if (map[nr][nc] == 1) continue;
			if (gasi_map[nr][nc] == 1) continue;
			if (visited[nr][nc] == 1) continue;

			visited[nr][nc] = 1;
			Queue[rear++] = (Node){ nr, nc, cur.t + 1 };
		}
	}

	return -1;
}

int main(void) {

	int N;

	int godori_r, godori_c;
	int gosuni_r, gosuni_c;

	int godori_home_r, godori_home_c;
	int gosuni_home_r, gosuni_home_c;

	(void)scanf("%d", &N);
	(void)scanf("%d %d %d %d", &godori_r, &godori_c, &godori_home_r, &godori_home_c);
	(void)scanf("%d %d %d %d", &gosuni_r, &gosuni_c, &gosuni_home_r, &gosuni_home_c);

	godori_r--; godori_c--;
	godori_home_r--; godori_home_c--;
	gosuni_r--; gosuni_c--;
	gosuni_home_r--; gosuni_home_c--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			(void)scanf("%d", &map[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			godori_gasi[i][j] = 0;
			gosuni_gasi[i][j] = 0;
		}
	}

	godori_gasi[godori_r][godori_c] = 0;
	gosuni_gasi[gosuni_r][gosuni_c] = 0;

	for (int i = 0; i < 8; i++) {
		int nr = godori_r + dr[i];
		int nc = godori_c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (map[nr][nc] == 1) continue;
		godori_gasi[nr][nc] = 1;
	}

	for (int i = 0; i < 8; i++) {
		int nr = gosuni_r + dr[i];
		int nc = gosuni_c + dc[i];

		if (nr < 0 || nr >= N || nc < 0 || nc >= N) continue;
		if (map[nr][nc] == 1) continue;
		gosuni_gasi[nr][nc] = 1;
	}

	godori_gasi[godori_r][godori_c] = 1;
	gosuni_gasi[gosuni_r][gosuni_c] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}

	int godori_t = BFS_godori(godori_r, godori_c, godori_home_r, godori_home_c, gosuni_gasi, N);


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}

	int gosuni_t = BFS_godori(gosuni_r, gosuni_c, gosuni_home_r, gosuni_home_c, godori_gasi, N);

	int result = 0;

	if (godori_t > gosuni_t) {
		result = godori_t;
	}

	else {
		result = gosuni_t;
	}

	printf("%d", result);

	return 0;
}
#endif 
