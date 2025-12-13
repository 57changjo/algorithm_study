#if 01
/*
산봉우리란 같은 높이를 가지는 하나의 격자 혹인 인접한 격자들의 집합
인접하다는 의미는 x좌표, y좌표가 각각 -1, 0, 1 차이나는 격자들
산봉우리와 인접한 격자는 모두 산봉우리보다 낮아야 한다
-> 문제 이해하고 BFS로 구현
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> farm;
vector<vector<bool>> visited;
int dr[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int dc[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
struct Point {
    int r, c;
};

void inputData() {
    cin >> N >> M;
	// NxM 농장
    farm.resize(N, vector<int>(M));
    visited.assign(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> farm[i][j];
        }
    }
}

int BFS() {
    queue<Point> q;
    int peakCount = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            if (visited[i][j] || farm[i][j] == 0)
                continue;

            q.push({ i, j });
            visited[i][j] = true;

            bool isPeak = true;
            int height = farm[i][j];

            while (!q.empty()) {
                Point cur = q.front();
                q.pop();

                for (int d = 0; d < 8; d++) {
                    int nr = cur.r + dr[d];
                    int nc = cur.c + dc[d];

                    // 범위 밖
                    if (nr < 0 || nr >= N || nc < 0 || nc >= M) 
                        continue;

                    // 더 높은 칸 발견 -> 산봉우리 아니다
                    if (farm[nr][nc] > height)
                        isPeak = false;

                    // 같은 높이 -> 같은 덩어리 -> 방문 확장
                    if (!visited[nr][nc] && farm[nr][nc] == height) {
                        visited[nr][nc] = true;
                        q.push({ nr, nc });
                    }
                }
            }

            if (isPeak)
                peakCount++;
        }
    }

    return peakCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inputData();
    cout << BFS();

    return 0;
}

#endif
