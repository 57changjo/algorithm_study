#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))


#define DEBUG 1

#define MAX_N (100+3)
#define MAX_M (100+3)
typedef struct _node {
	int r, c;
}node;

node Q[MAX_N * MAX_N];

int front, rear;
int N, M;

int map[MAX_N][MAX_M];


/*void printmap() {
	printf("%d %d\n", N, M);
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}*/

void inputData(void) {
	char temp[MAX_N] = { 0 };
	(void)scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; ++i) {
		(void)scanf("%s", temp + 1);
		for (int j = 1; j <= M; ++j) {
			map[i][j] = temp[j] - '0';
		}
	}
}


int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int BFS() {			
	node current = { 0,0 };
	int nr, nc;
	Q[rear++] = (node){ 1,1 };	
	map[1][1] = 2;					
	while (front != rear) {
		current = Q[front++];			
		for (int i = 0; i < 4; ++i) {
			nr = current.r + dr[i];		
			nc = current.c + dc[i];
			if (map[nr][nc] != 1) continue;			
			Q[rear++] = (node){ nr,nc };		
			map[nr][nc] = (map[current.r][current.c] + 1);			
			if (nr == N && nc == M)						
				return map[nr][nc] - 1;			
		}
	}
	return 0;
}

int main() {
#if DEBUG 
	(void)freopen("prob2.txt", "r", stdin);
#endif
	inputData();
	printf("%d", BFS());
	return 0;
}

#endif