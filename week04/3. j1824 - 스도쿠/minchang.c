#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int SUDOKU[9][9];

void inputData(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            (void)scanf("%d", &SUDOKU[i][j]);
        }
    }
}

void printData(void) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            (void)printf("%d ", SUDOKU[i][j]);
        }
        (void)printf("\n");
    }
}

int isValid(int r, int c, int v) {
    for (int i = 0; i < 9; ++i) {
        if (SUDOKU[r][i] == v) return 0;
        if (SUDOKU[i][c] == v) return 0;
    }

    int sr = (r / 3) * 3;
    int sc = (c / 3) * 3;
    for (int i = sr; i < sr + 3; ++i)
        for (int j = sc; j < sc + 3; ++j)
            if (SUDOKU[i][j] == v) return 0;

    return 1;
}

int solve(void) {
    int r = -1, c = -1;
    // r을 flag 처럼 사용: break로는 이중 for문 탈출 불가
    for (int i = 0; i < 9 && r == -1; ++i) {
        for (int j = 0; j < 9; ++j) {
            if (SUDOKU[i][j] == 0) {
                r = i; c = j;
                break;
            }
        }
    }
    // r이 그대로 -1이면 빈칸 없는 상황이므로 종료
    if (r == -1) return 1;

    for (int v = 1; v <= 9; ++v) {
        if (isValid(r, c, v)) {
            SUDOKU[r][c] = v;
            // return을 통한 재귀 탈출
            if (solve()) return 1;
            SUDOKU[r][c] = 0;
        }
    }
    return 0;
}

int main(void) {
    //(void)freopen("j1824.txt", "r", stdin);
    inputData();
    (void)solve();
    printData();
    return 0;
}
#endif
