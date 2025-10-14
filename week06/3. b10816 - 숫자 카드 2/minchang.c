#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_VAL (10000000+1)

int pos_counts[MAX_VAL];
int neg_counts[MAX_VAL];

int N;
int M;

void inputData(void) {
    (void)scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int card;
        (void)scanf("%d", &card);
        if (card >= 0) {
            pos_counts[card]++;
        }
        else {
            neg_counts[-card]++;
        }
    }
}

void solve(void) {
    (void)scanf("%d", &M);
    for (int i = 0; i < M; ++i) {
        int query;
        (void)scanf("%d", &query);
        if (query >= 0) {
            printf("%d ", pos_counts[query]);
        }
        else {
            printf("%d ", neg_counts[-query]);
        }
    }
}

int main(void) {
    //(void)freopen("b10816.txt", "r", stdin);
    inputData();
    solve();

    return 0;
}

#endif
