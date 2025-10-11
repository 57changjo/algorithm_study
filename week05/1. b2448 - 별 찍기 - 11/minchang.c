#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// N의 최대값 3072, 폭은 2*N-1
char arr[3072][6144];

void draw_star(int n, int row, int col) {
    if (n == 3) {
        arr[row][col] = '*';
        arr[row + 1][col - 1] = '*';
        arr[row + 1][col + 1] = '*';
        arr[row + 2][col - 2] = '*';
        arr[row + 2][col - 1] = '*';
        arr[row + 2][col] = '*';
        arr[row + 2][col + 1] = '*';
        arr[row + 2][col + 2] = '*';
        return;
    }

    int half = n / 2;
    // 위쪽
    draw_star(half, row, col);
    // 왼쪽 아래
    draw_star(half, row + half, col - half);
    // 오른쪽 아래
    draw_star(half, row + half, col + half);
}

void print_arr(int N) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < 2 * N - 1; ++j) {
			printf("%c", arr[i][j]);
        }
		printf("\n");
	}
}

int main(void) {
    int N;
	(void)freopen("b2448.txt", "r", stdin);
    (void)scanf("%d", &N);

    memset(arr, ' ', sizeof(arr));

    draw_star(N, 0, N - 1);
	print_arr(N);

    return 0;
}

#endif
