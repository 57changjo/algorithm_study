#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N;
int MAX_K;
int W[101];
int V[101];
int dp[101][100001];

int max(int a, int b) {
    return (a > b) ? a : b;
}

void inputData(void) {
    (void)scanf("%d %d", &N, &MAX_K);

    for (int i = 1; i <= N; i++) {
        (void)scanf("%d %d", &W[i], &V[i]);
    }
}

void solve(void) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= MAX_K; j++) {

            int curr_w = W[i];
            int curr_v = V[i];

            // 어차피 못 넣으므로 이전 값 복사
            if (curr_w > j) {
                dp[i][j] = dp[i - 1][j];
            }
            else {
                // 안 넣는 경우
                int val_notInclude = dp[i - 1][j];
				// 넣는 경우: 현재 가치 + 남은 무게에 대한 최대 가치
                int val_Include = curr_v + dp[i - 1][j - curr_w];
				// 둘 중 큰 값 선택
                dp[i][j] = max(val_notInclude, val_Include);
            }
        }
    }

    printf("%d", dp[N][MAX_K]);
}

int main(void) {
    //(void)freopen("b12865.txt", "r", stdin);
    inputData();
    solve();

    return 0;
}

#endif
