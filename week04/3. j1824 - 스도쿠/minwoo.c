#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 100

int sudoku[SIZE][SIZE];
int r, c;

int check(int r, int c, int val) {

// 3x3 블록 안에서 체크해보자
// 좌표 r,c 가 있다면 해당 칸이 속한 3x3 블록은 
// int sr = (r / 3) * 3 & sc = (c / 3) * 3 이렇게 구한다 이게 해당 좌표의 맨 위 왼쪽 스타트 구할 수 있다

	int sr = (r / 3) * 3;
	int sc = (c / 3) * 3;

	for (int i = sr; i < sr + 3; i++) {
		for (int j = sc; j < sc + 3; j++) {
			if (sudoku[i][j] == val) return 0;
		}
	}

	for (int i = 0; i < 9; i++) {
		if (sudoku[r][i] == val)
			return 0;
	}

	for (int j = 0; j < 9; j++) {
		if (sudoku[j][c] == val) {
			return 0;
		}
	}

	return 1;
}

void solve(int r, int c) {

	if (c == 9) {
		solve(r + 1, 0);
		return;
	}

	if (r == 9) {

		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", sudoku[i][j]);
			}
			printf("\n");
		}
		exit(0);
	}

	if (sudoku[r][c] != 0) {
		solve(r, c + 1);
	}

	else {

		for (int val = 1; val <= 9; val++) {
			if (check(r, c, val)) {
				sudoku[r][c] = val;
				solve(r, c + 1);
				sudoku[r][c] = 0;
			}
		}
	}
}

int main(void) {

	(void)freopen("j1814.txt", "r", stdin);
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			(void)scanf("%d", &sudoku[i][j]);
		}
	}

	solve(0, 0);

	return 0;
}
