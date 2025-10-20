#include <stdio.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int coin[100];
    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    int dp[10001] = {0}; 
    dp[0] = 1; 


    for (int i = 0; i < n; i++) {
        for (int j = coin[i]; j <= k; j++) {
            dp[j] += dp[j - coin[i]];
        }
    }

    printf("%d\n", dp[k]);
    return 0;
}
