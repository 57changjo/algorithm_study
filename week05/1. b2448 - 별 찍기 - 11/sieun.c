// b2448 별 찍기 11
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 3072  // N = 3 * 2^10 = 3072

char canvas[MAX_N][MAX_N * 2];  // 공백 포함

void draw_triangle(int size, int r, int c) {
    if (size == 3) {
        // 기본 삼각형
        canvas[r][c] = '*';
        canvas[r + 1][c - 1] = '*';
        canvas[r + 1][c + 1] = '*';
        for (int dc = -2; dc <= 2; dc++) {
            canvas[r + 2][c + dc] = '*';
        }
        return;
    }
    int half = size / 2;
    // 위쪽
    draw_triangle(half, r, c);
    // 왼쪽 아래
    draw_triangle(half, r + half, c - half);
    // 오른쪽 아래
    draw_triangle(half, r + half, c + half);
}

int main() {
    int N;
    scanf("%d", &N);
    int width = 2 * N - 1;

    // init
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < width; j++) {
            canvas[i][j] = ' ';
        }
    }

    // 맨 위의 점
    draw_triangle(N, 0, N - 1);

    // 출력
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < width; j++) {
            putchar(canvas[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

#endif
