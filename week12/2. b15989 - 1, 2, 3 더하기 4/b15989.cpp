#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int dp[100001][4];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    dp[1][1] = 1;
    dp[2][1] = dp[2][2] = 1;
    dp[3][1] = dp[3][2] = dp[3][3] = 1;
    
    for(int i=4; i<10001; i++)
    {
        dp[i][1] = dp[i-1][1];  //i를 1로 만드는 경우
        dp[i][2] = dp[i-2][1] + dp[i-2][2]; //i를 1, 2로 만드는 경우
        dp[i][3] = dp[i-3][1] + dp[i-3][2] + dp[i-3][3]; //i를 1, 2, 3으로 만드는 경우
    }

    int N;
    while(T--)
    {
        cin >> N;
        cout << dp[N][1] + dp[N][2] + dp[N][3] << "\n";
    }

    return 0;
}
