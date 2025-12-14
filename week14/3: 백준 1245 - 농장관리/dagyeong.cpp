#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M;
int map[101][71];
bool visited[101][71];
int cnt;

int dr[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dc[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void inputData(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
}

void solve(int i, int j) { // 같은 높이 영역 찾기
    queue<pair<int, int>> q;
    pair<int, int> curr;

    q.push({ i, j });
    visited[i][j] = true;

    bool isPeak = true;
    int height = map[i][j];

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        for (int d = 0; d < 8; d++) { // 인접한 격자 체크
            int nr = curr.first + dr[d];
            int nc = curr.second + dc[d];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (map[nr][nc] > height) {
                isPeak = false;
            }
            else if (map[nr][nc] == height && !visited[nr][nc]) { // 산봉우리 확장
                visited[nr][nc] = true;
                q.push({ nr, nc });
            }
        }
    }

    if (isPeak) {
        cnt++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b1245.txt", "r", stdin);
    inputData();
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                solve(i, j);
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
#endif
