#include <iostream>
using namespace std;

int candy[1001][1001];
int dp[1001][1001];

int main() {
    int N, M;
    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> candy[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            int maxPrev = dp[i-1][j];          
            if (dp[i][j-1] > maxPrev) maxPrev = dp[i][j-1];    
            if (dp[i-1][j-1] > maxPrev) maxPrev = dp[i-1][j-1];
            dp[i][j] = maxPrev + candy[i][j];  
        }
    }

    cout << dp[N][M] << "\n";
    return 0;
}
