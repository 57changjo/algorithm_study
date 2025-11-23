#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
// connected[i][j] = true 라면 i가 j보다 키가 작다는 것이 증명됨
// 작은 걸 내가 아는 거랑, 본인 입장에서 아는 거랑 다르다.
bool connected[501][501];

void input(void) {
    //(void)freopen("b2458.txt", "r", stdin);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            connected[i][j] = false;
        }
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        connected[a][b] = true; // a가 b보다 작다
    }
}

void solve(void) {
    // k: 경유지
    for (int k = 1; k <= N; k++) {
        // i: 출발지
        for (int i = 1; i <= N; i++) {
            // j: 도착지
            for (int j = 1; j <= N; j++) {
				// i < k고, k < j면 i < j
                if (connected[i][k] && connected[k][j]) {
                    connected[i][j] = true;
                }
            }
        }
    }

    int ans = 0;

    for (int i = 1; i <= N; i++) {
        int know_count = 0;

        for (int j = 1; j <= N; j++) {
            if (i == j) continue;

            if (connected[i][j] || connected[j][i]) {
                know_count++;
            }
        }

        if (know_count == N - 1) {
            ans++;
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

