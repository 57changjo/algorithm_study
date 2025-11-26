#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Shortcut {
    int start;
    int end;
    int len;
};

int N, D;
vector<Shortcut> shortcuts;
int dp[10001];

void input(void) {

    //(void)freopen("b1446.txt", "r", stdin);

    cin >> N >> D;
    for (int i = 0; i < N; i++) {
        int start, end, length;
        cin >> start >> end >> length;

        if (end <= D && (end - start) > length) {
            shortcuts.push_back({ start, end, length });
        }
    }
}

void solve(void) {

    for (int i = 0; i <= D; i++) {
        dp[i] = i;
    }

    for (int i = 0; i <= D; i++) {
        if (i > 0) {
            dp[i] = min(dp[i], dp[i - 1] + 1);
        }

        for (auto sc : shortcuts) {
            if (sc.start == i) {
                if (dp[sc.end] > dp[i] + sc.len) {
                    dp[sc.end] = dp[i] + sc.len;
                }
            }
        }
    }

    cout << dp[D];
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return 0;
}
