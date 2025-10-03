#include <stdio.h>

#define SIZE 9

int board[SIZE][SIZE];
int solved = 0;


int check(int row, int col, int num) {
    for (int j = 0; j < SIZE; j++) {
        if (board[row][j] == num) return 0;
    }
    for (int i = 0; i < SIZE; i++) {
        if (board[i][col] == num) return 0;
    }
    int sr = (row / 3) * 3;
    int sc = (col / 3) * 3;
    for (int i = sr; i < sr + 3; i++) {
        for (int j = sc; j < sc + 3; j++) {
            if (board[i][j] == num) return 0;
        }
    }
    return 1;
}
void solve(int row, int col) {
    if (row == SIZE) { 
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                printf("%d ", board[i][j]);
            }
            printf("\n");
        }
        solved = 1;
        return;
    }
    int nextRow = row;
    int nextCol = col + 1;
    if (nextCol == SIZE) {
        nextRow++;
        nextCol = 0;
    }

    if (board[row][col] != 0) {
        solve(nextRow, nextCol);
    } else {
        for (int num = 1; num <= 9; num++) {
            if (check(row, col, num)) {
                board[row][col] = num;
                solve(nextRow, nextCol);
                if (solved) return; 
                board[row][col] = 0; 
            }
        }
    }
}

int main() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    solve(0, 0);
    return 0;
}
