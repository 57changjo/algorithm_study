#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
vector<int> score(301, 0);
vector<vector<int>> DP(301, vector<int>(2)); // i번째 계단에 오를때 점수의 최댓값 저장할 것.

//void DFS(int n, int cnt, int total) {
//    if (n > K || cnt >= 2) {
//        return;
//    }
//    else if (n == K && cnt < 2) {
//        sum_max = max(sum_max, total);
//        return;
//    }
//
//    DFS(n + 1, cnt + 1, total + score[n + 1]);
//    DFS(n + 2, 0, total + score[n + 2]);
//}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    (void)freopen("b2579.txt", "r", stdin);

    cin >> K;
    for (int i = 1; i <= K; ++i) {
        cin >> score[i];
    }

    DP[1][0] = score[1];
    for (int i =2; i <= K; ++i) {
        DP[i][0] = max(DP[i - 2][0], DP[i - 2][1]) + score[i];
        DP[i][1] = DP[i - 1][0] + score[i];
    }

    //DFS(1, 0, score[1]);
    //if (K>=2) DFS(2, 0, score[2]);

    cout << max(DP[K][0], DP[K][1]);
    return 0;
}
