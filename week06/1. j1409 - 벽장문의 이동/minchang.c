#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_N (20+1)

int N;
int closet[MAX_N];
int lenofQ;
int Queue[MAX_N];
int opened1, opened2;
int minmove = INT_MAX;

void dfs(int opened1, int opened2, int q_idx, int move_count) {
    if (q_idx > lenofQ) {
        if (move_count < minmove) {
            minmove = move_count;
        }
        return;
    }

    int next_closet = Queue[q_idx];

	// 이동 횟수는 index 차이의 절댓값
    int move1 = abs(opened1 - next_closet);
    dfs(next_closet, opened2, q_idx + 1, move_count + move1);

    int move2 = abs(opened2 - next_closet);
    dfs(opened1, next_closet, q_idx + 1, move_count + move2);
}

void inputData(void) {
    (void)scanf("%d", &N);
    (void)scanf("%d %d", &opened1, &opened2);
    (void)scanf("%d", &lenofQ);
    for (int i = 1; i <= lenofQ; ++i) {
        (void)scanf("%d", &Queue[i]);
    }
}

int main(void) {
    //(void)freopen("j2666.txt", "r", stdin);
    inputData();
    dfs(opened1, opened2, 1, 0);
    printf("%d", minmove);
    return 0;
}
#endif
