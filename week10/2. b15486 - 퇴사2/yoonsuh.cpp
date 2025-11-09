#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> T(N+2); 
    vector<int> P(N+2);
    for (int i = 1; i <= N; i++)
        cin >> T[i] >> P[i];

    vector<int> dp(N+2, 0);
    int maxMoney = 0;      

    for (int i = 1; i <= N+1; i++) {
        if (dp[i] < maxMoney)
            dp[i] = maxMoney;
      
        int finishDay = i + T[i];
      
        if (finishDay <= N+1) {
            dp[finishDay] = max(dp[finishDay], dp[i] + P[i]);
        }
        maxMoney = max(maxMoney, dp[i]);
    }
    cout << maxMoney;
}
