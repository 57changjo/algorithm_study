#include <stdio.h>

int main(void) {
    int N, K;
    scanf("%d %d", &N, &K);

    int W[101];     
    int V[101];     
    int dp[100001]; 
    for (int i = 1; i <= N; i++) {
        scanf("%d %d", &W[i], &V[i]);
    }

    for (int w = 0; w <= K; w++) {
        dp[w] = 0;
    }
    for (int i = 1; i <= N; i++) {
        for (int w = K; w >= W[i]; w--) {
            if (dp[w] < dp[w - W[i]] + V[i]) {
                dp[w] = dp[w - W[i]] + V[i];
            }
        }
    }

    printf("%d\n", dp[K]);
    return 0;
}
