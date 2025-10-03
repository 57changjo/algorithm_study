#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 9

int board[SIZE][SIZE];

typedef struct { 
    int r, c; 
} Node;
Node ecells[SIZE*SIZE]; // empty cells
int emptycnt = 0;

void inputData() {
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            scanf("%d", &board[r][c]);
            // 빈칸
            if (board[r][c] == 0) {
                ecells[emptycnt++] = (Node){ r, c };
            }
        }
    }
}

// r,c 위치에 num을 넣을 수 있는지=
bool RCplace(int r, int c, int num) {
    // r,c 체크
    for (int i = 0; i < SIZE; i++) {
        if (board[r][i] == num) return false;
        if (board[i][c] == num) return false;
    }

    // 3x3 블록 체크
    int br = (r / 3) * 3;
    int bc = (c / 3) * 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[br + i][bc + j] == num) return false;
        }
    }

    return true;
}

bool solve(int idx) {
    if (idx == emptycnt) return true; // 모든 빈칸 채움

    int r = ecells[idx].r;
    int c = ecells[idx].c;

    for (int num = 1; num <= 9; num++) {
        if (RCplace(r, c, num)) {
            board[r][c] = num;
            if (solve(idx + 1)) return true; // 성공하면 종료
            board[r][c] = 0; // 백트래킹
        }
    }
    return false; // 이 칸에 넣을 수 있는 수 없음
}

int main(void) {
    inputData();
    // result print
    if (solve(0)) { // 시작 idx 0
        for (int r = 0; r < SIZE; r++) {
            for (int c = 0; c < SIZE; c++) {
                printf("%d ", board[r][c]);
            }
            printf("\n");
        }
    }
    else {
        printf("IMPOSSIBLE\n");
    }

    return 0;
}

#endif
