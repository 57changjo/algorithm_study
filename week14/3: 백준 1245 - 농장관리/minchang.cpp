#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int Map[102][72];
bool visited[102][72];

// 좌상, 상, 우상, 좌, 우, 좌하, 하, 우하
int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void inputData(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> Map[i][j];
            visited[i][j] = false;
        }
    }
}

// 같은 높이 덩어리가 산봉우리인지 판별
bool bfs(int r, int c) {
    queue<pair<int, int>> q;
    q.push({ r, c });
    visited[r][c] = true;
    
    bool isPeak = true; // 현재 덩어리를 일단 산봉우리라고 가정
    int height = Map[r][c];

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();

        int cr = curr.first;
        int cc = curr.second;

        for (int i = 0; i < 8; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

            // 인접한 곳이 현재 높이보다 높으면 산봉우리가 아님
            if (Map[nr][nc] > height) {
                isPeak = false; 
            }
            // 높이가 같고 아직 방문하지 않았다면 같은 덩어리니까 큐에 추가
            else if (Map[nr][nc] == height && !visited[nr][nc]) {
                visited[nr][nc] = true;
                q.push({ nr, nc });
            }
        }
    }
    return isPeak;
}

void solve(void) {
    int peakCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            // 방문하지 않았고, 산봉우리 덩어리라면 카운트
            // bfs에서 같은 높이만 방문 처리 했음
            if (!visited[i][j]) {
                if (bfs(i, j)) {
                    peakCount++;
                }
            }
        }
    }
    cout << peakCount;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // (void)freopen("b1245.txt", "r", stdin);

    inputData();
    solve();

    return 0;
}
