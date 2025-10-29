#include <stdio.h>
#include <string.h>

#define MAX 1000

int dp[MAX + 1][MAX + 1];

int main(void) {
    char A[MAX + 1];
    char B[MAX + 1];

    scanf("%s", A);
    scanf("%s", B);

    int lenA = strlen(A);
    int lenB = strlen(B);

    for (int i = 1; i <= lenA; i++) {
        for (int j = 1; j <= lenB; j++) {
            if (A[i - 1] == B[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }
    }

    printf("%d\n", dp[lenA][lenB]);
    return 0;
}
