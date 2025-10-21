#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 0

#define MAX_THINGS 101
#define MAX_WEIGHT 100001

int find_max(int a, int b) {

    return (a > b) ? a : b;
}

int main(void) {

    int N, K;
    int W[MAX_THINGS] = { 0 };
    int V[MAX_THINGS] = { 0 };
    int max_value[MAX_WEIGHT] = { 0 };

    (void)scanf("%d %d", &N, &K);

    for (int i = 1; i <= N; i++) {
        (void)scanf("%d %d", &W[i], &V[i]);
    }

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= W[i]; j--) {
            max_value[j] = find_max(max_value[j], max_value[j - W[i]] + V[i]);
        }
    }

    printf("%d", max_value[K]);

    return 0;
}
#endif
