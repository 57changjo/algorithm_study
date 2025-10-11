// 3번 스도쿠
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[11][11];
int visitedR[10][10]; // visitedR[i][j]: i번째줄의 숫자 j가 있는지
int visitedC[10][10];
int visitedBox[3][3][10];

void inputData(void) {
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			(void)scanf("%d", map[i] + j);
			if (!map[i][j]) continue;
			visitedR[i][map[i][j]] = 1;
			visitedR[i][0]++;
			visitedC[j][map[i][j]] = 1;
			visitedC[j][0]++;
			visitedBox[(i - 1) / 3][(j - 1) / 3][map[i][j]] = 1;
			visitedBox[(i - 1) / 3][(j - 1) / 3][0]++;
		}
	}
}

void printData(void) {
	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void DFS(int L, int sr, int sc, int num) {

	for (int i = 1; i < 10; ++i) {
		for (int j = 1; j < 10; ++j) {
			if (map[i][j] == 0) {
				for (int k = 1; k <= 9; ++k) {
					if ((visitedR[i][k] == 0) && (visitedC[j][k] == 0) && (visitedBox[(i - 1) / 3][(j - 1) / 3][k] == 0)) {
						map[i][j] = k;
			
						visitedR[i][k] = 1;
						visitedR[i][0]++;
						visitedC[j][k] = 1;
						visitedC[j][0]++;
						visitedBox[(i - 1) / 3][(j - 1) / 3][k] = 1;
						visitedBox[(i - 1) / 3][(j - 1) / 3][0]++;

						DFS(L + 1, i, j, k);						
					}
				}
				if (!map[i][j]) {
					map[sr][sc] = 0;

					visitedR[sr][num] = 0;
					visitedR[sr][0]--;
					visitedC[sc][num] = 0;
					visitedC[sc][0]--;
					visitedBox[(sr - 1) / 3][(sc - 1) / 3][num] = 0;
					visitedBox[(sr - 1) / 3][(sc - 1) / 3][0]--;
					return;
				}
			}
		}
	}

}

int main(void) {
	//(void)freopen("j1824.txt", "r", stdin);
	inputData();
	DFS(1, 0, 0, 0);
	printData();
}
#endif
