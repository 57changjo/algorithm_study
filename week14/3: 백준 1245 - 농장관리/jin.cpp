#include <bits/stdc++.h>
using namespace std;

/*
 * n, m : 지도 크기
 * height : 각 칸의 높이 정보
 * visited : 이미 처리한 칸인지 여부
 */
int n, m;
int heightMap[101][71];
bool visited[101][71];

/*
 * 8방향 이동 (상, 우상, 우, 우하, 하, 좌하, 좌, 좌상)
 */
const pair<int, int> directions[8] = {
    {1, 0}, {1, 1}, {0, 1}, {-1, 1},
    {-1, 0}, {-1, -1}, {0, -1}, {1, -1}
};

/*
 * (sx, sy)를 시작점으로 같은 높이의 영역을 BFS로 탐색
 * 이 영역이 "산봉우리"인지 여부를 반환한다.
 */
bool isPeak(int sx, int sy) {
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = true;

    bool peak = true;   // 주변에 더 높은 곳이 하나라도 있으면 false

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int d = 0; d < 8; d++) {
            int nx = x + directions[d].first;
            int ny = y + directions[d].second;

            // 지도 범위를 벗어나면 무시
            if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                continue;

            // 시작 높이보다 더 높은 곳이 인접해 있으면 산봉우리가 아님
            if (heightMap[nx][ny] > heightMap[sx][sy]) {
                peak = false;
            }

            // 같은 높이이고 아직 방문하지 않았다면 같은 영역으로 확장
            if (!visited[nx][ny] && heightMap[nx][ny] == heightMap[sx][sy]) {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }

    return peak;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    // 지도 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> heightMap[i][j];
        }
    }

    int peakCount = 0;

    // 모든 칸을 순회하면서 아직 방문하지 않은 곳에서 BFS 시작
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                if (isPeak(i, j)) {
                    peakCount++;
                }
            }
        }
    }

    cout << peakCount << '\n';
    return 0;
}
