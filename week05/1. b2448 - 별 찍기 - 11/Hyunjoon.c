#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#if 1
char map[3072][6144];

void star(int r, int c, int N) {          //재귀를 통해 n==3일 때 row column의 값만 바꿔서 새끼트리 치게 함
	if (N == 3) {
		map[r][c] = '*';
		map[r + 1][c - 1] = '*';
		map[r + 1][c + 1] = '*';
		map[r + 2][c - 2] = '*';
		map[r + 2][c - 1] = '*';
		map[r + 2][c] = '*';
		map[r + 2][c + 1] = '*';
		map[r + 2][c + 2] = '*';

	}
	else {
		star(r, c, N/2);                        
		star(r + N / 2, c - N / 2, N/2);              
		star(r + N / 2, c + N / 2, N/2);
	}

}

int main(void) {
	int N;
	(void)freopen("prob1.txt", "r", stdin);
	(void)scanf("%d", &N);
	star(0, N-1, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N; j++){
			if (map[i][j] != 0)
				printf("%c", map[i][j]);
			else printf(" ");
		}
		printf("\n");
	}
	return 0;
}
#endif
