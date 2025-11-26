#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> houses;

void input(void) {
    //(void)freopen("b2110.txt", "r", stdin);
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        houses.push_back(temp);
    }
}

bool canInstall(int dist) {
    int count = 1;
    int last_installed = houses[0];

    for (int i = 1; i < N; i++) {
        if ((houses[i] - last_installed) >= dist) {
            count++;
            last_installed = houses[i];
        }
    }
    return count >= C;
}

void solve(void) {
    sort(houses.begin(), houses.end());

    int left = 1;
    int right = houses[N - 1] - houses[0];
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (canInstall(mid)) {
            ans = mid;
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    input();
    solve();
    return 0;
}

