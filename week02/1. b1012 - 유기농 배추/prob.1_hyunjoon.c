#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#define MAX_M (50+2)
#define MAX_N (50+2)

typedef struct _node {
	int r, c;
}node;
int front, rear;
node Q[MAX_N * MAX_M];

int map[MAX_N][MAX_M];
int visited[MAX_N][MAX_M];

int N, M;
int Cab;
int m, n;
int Test_n;
int cnt;

void inputData(void); 
void printData();
void cleanData();
int Solve();
void BFS(int sC, int sR);

void printData_Debug();

void inputData(void) {
	(void)scanf("%d %d %d", &M, &N, &Cab);
		for (int j = 0; j < Cab; ++j) {
			(void)scanf("%d %d", &m, &n);
			map[n][m] = 1;
		}
}

void printData() {
	printf("%d %d %d\n", N, M, Cab);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j){
			printf("%d", map[i][j]);
		}
		printf("\n");
	}
printf("\n");
}


void printData_Debug() {
	printf("%d %d %d\n", N, M, Cab);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {\
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("DEBUG PRINT\n");
}


void cleanData() {
	cnt = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			map[i][j] = 0;
		}
	}
	front = 0;
	rear = 0;
}     //BFS µÎ¹ø



int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
int Solve() {
	int i, j;
	for (i = 0; i < N; ++i) {
		for (j = 0; j < M; ++j){
			if (map[i][j] && !visited[i][j]) {
				BFS(i , j);
				cnt++;
				}
			}
	}
	return cnt;
}

void BFS(int sC, int sR) {
	node current = { 0,0 };
	int nr, nc;
	Q[rear++] = (node){ sR, sC };
	while (front != rear) {
		current = Q[front++];
		for (int i = 0; i < 4; ++i) {
			nr = current.r + dr[i];
			nc = current.c + dc[i];
			if (nr < 0 || nr > M  || nc < 0 || nc > N ) 
				continue;
			if (map[nc][nr] && !visited[nc][nr]) {
				Q[rear++] = (node){ nr,nc };
				visited[nc][nr] = 1;
			}
		}
	}
}

int main() {
	int test_n=0;
	(void)freopen("prob1.txt", "r", stdin);
	(void)scanf("%d", &test_n);
	while (test_n--) {
		inputData();
		printData();
		printf("answer : %d\n", Solve());
		printData_Debug();
		cleanData();
	}

	return 0;
}

