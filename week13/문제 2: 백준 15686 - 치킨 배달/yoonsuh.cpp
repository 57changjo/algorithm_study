#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int,int>> home, chick;

    // 지도 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            if (x == 1) home.push_back({i, j});
            if (x == 2) chick.push_back({i, j});
        }
    }

    int c = chick.size();
    vector<int> pick(c, 0);
    fill(pick.end() - m, pick.end(), 1);  

    int answer = 1000000;

    do {
        int total = 0;

        for (auto &h : home) {
            int hx = h.first, hy = h.second;
            int dist = 1e9;
            for (int i = 0; i < c; i++) {
                if (pick[i]) {
                    int cx = chick[i].first, cy = chick[i].second;
                    dist = min(dist, abs(hx - cx) + abs(hy - cy));
                }
            }
            total += dist;
        }

        answer = min(answer, total);
    } while (next_permutation(pick.begin(), pick.end()));

    cout << answer;
}
