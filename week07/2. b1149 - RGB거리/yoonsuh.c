#include <stdio.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

int main() {
    int N;
    scanf("%d", &N);

    int cost[1000][3];
    int dp[1000][3];   

    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
    }

    dp[0][0] = cost[0][0]; // 빨강
    dp[0][1] = cost[0][1]; // 초록
    dp[0][2] = cost[0][2]; // 파랑

    
    for (int i = 1; i < N; i++) {
        dp[i][0] = MIN(dp[i-1][1], dp[i-1][2]) + cost[i][0]; 
        dp[i][1] = MIN(dp[i-1][0], dp[i-1][2]) + cost[i][1]; 
        dp[i][2] = MIN(dp[i-1][0], dp[i-1][1]) + cost[i][2]; 
    }

  
    int result = MIN(MIN(dp[N-1][0], dp[N-1][1]), dp[N-1][2]);
    printf("%d\n", result);

    return 0;
}
