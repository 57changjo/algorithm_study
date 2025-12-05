#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int T;
vector<int> DP(10010);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b15989.txt", "r", stdin);
    cin >> T;

    DP[5] = 1; // 숫자 0 의 DP
    for (int i = 6; i <= 10005; i++) {
        DP[i] = DP[i - 1] + DP[i - 2] - DP[i - 4] - DP[i - 5] + DP[i - 6];
    }

    while (T--) {
        int n = 0;
        cin >> n;
        
        cout << DP[n + 5] << endl;
    }

    return 0;
}
