#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum { sp = 0,  ep = 1, length = 2 };

int N, D;
int trueN;
vector<vector<int>> list;

void inputData(void) {
    cin >> N >> D;
    for (int i = 0; i < N; ++i) {
        int s, e, l;
        cin >> s >> e >> l;
        if (e > D) continue;
        if (e - s <= l) continue;
        list.push_back({ s, e, l });
        trueN++;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b1446.txt", "r", stdin);
    inputData();

    vector<int> DP(D + 1, INT_MAX);
    DP[0] = 0;

    for (int i = 1; i <= D; ++i) {
        DP[i] = min(DP[i - 1] + 1, DP[i]);

        for (int j = 0; j < trueN; ++j) {
            if (list[j][ep] <= i) {
                DP[list[j][ep]] = min(DP[list[j][sp]] + list[j][length], DP[list[j][ep]]);
            }
        }

    }

    cout << DP[D];
    return 0;
}

#endif
