// 1번 별 찍기
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 6144 //(2^10)*6

int N;
char map[MAX][MAX]; // 0행 1열부터

void initMap(void) {
	for (int i = 0; i < N; i++) {
		memset(map[i]+1, ' ', 2*N - 1); //공백으로 초기화
	}	
}

void drawMap(void) {
	for (int i = 0; i < N; ++i) {
		printf("%s\n", map[i]+1);
	}
}

void drawStars(int sr, int sc) {
	map[sr][sc] = '*';
	map[sr + 1][sc - 1] = '*';
	map[sr + 1][sc + 1] = '*';
	for (int i = -2; i < 3; i++) {
		map[sr + 2][sc + i] = '*';
	}
}

void DFS(int n, int sr, int sc) {
	if (n/3 == 1) {
		drawStars(sr, sc);
		return;
	}
	DFS(n / 2, sr, sc + 0);
	DFS(n / 2, sr + n / 2, sc - n / 2);
	DFS(n / 2, sr + n / 2, sc + n / 2);
}

int main(void) {
	(void)scanf("%d", &N); //24
	initMap();
	//drawMap();
	DFS(N, 0, N);
	drawMap();
}
#endif
