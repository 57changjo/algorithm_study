#if 01
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N = 0;
    cin >> N;

    vector<int> stair(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> stair[i];

    // DP[i] = i번째 계단까지 올랐을 때 얻을 수 있는 최대 점수
    vector<int> DP(N + 1, 0);
    DP[1] = stair[1];
    DP[2] = stair[1] + stair[2];
    DP[3] = max(stair[1] + stair[3], stair[2] + stair[3]);

    // DP[i-2] + stair[i] → i-2에서 한 칸 건너뛰고 i로 온 경우 (연속 1)
    // DP[i - 3] + stair[i - 1] + stair[i] → i-3 → i-1 → i로 온 경우(연속 2)
    for (int i = 4; i <= N; i++) {
        DP[i] = max(DP[i - 2], DP[i - 3] + stair[i - 1]) + stair[i];
    }
    cout << DP[N];
    
    return 0;
}

#endif
