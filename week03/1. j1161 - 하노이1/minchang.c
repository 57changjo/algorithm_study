#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void move(int disk, int from, int to) {
    printf("%d : %d -> %d\n", disk, from, to);
}

void hanoi(int n, int from, int by, int to) {
    if (n == 0) return;
    hanoi(n - 1, from, to, by);
    move(n, from, to);
    hanoi(n - 1, by, from, to);
}

int main(void) {
    int N;
	//(void)freopen("j1161.txt", "r", stdin);
    if (scanf("%d", &N) != 1) {
        return 0;
    }
    hanoi(N, 1, 2, 3);
    return 0;
}

#endif
