// b16236 - 아기상어
#if 01
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, sR, sC, nR, nC, meal;
int shark = 2;
vector<vector<int>> sea;
vector<vector<int>> visited;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
struct Node {
    int r, c;
};
struct Result {
    int time, r, c;
};

Result BFS(int sR, int sC) {
    queue<Node> q;
    q.push({ sR, sC });
    visited.assign(N, vector<int>(N, -1));
    visited[sR][sC] = 0;

    // 좌표쌍들을 여러 개 저장할 수 있는 -> 물고기 행, 열
    vector<pair<int, int>> fishList;

    while (!q.empty()) {
        int qSize = q.size(); // 현재 거리(level)의 노드 개수
        fishList.clear();

        // BFS를 '거리 단위로 끊어서 처리하는 장치'
        for (int i = 0; i < qSize; i++) {
            Node curr = q.front();
            q.pop();

            for (int dir = 0; dir < 4; dir++) {
                nR = curr.r + dr[dir];
                nC = curr.c + dc[dir];

                if (nR < 0 || nR >= N || nC < 0 || nC >= N)
                    continue;
                if (visited[nR][nC] != -1)
                    continue;
                if (sea[nR][nC] > shark)
                    continue;

                visited[nR][nC] = visited[curr.r][curr.c] + 1;

                // 먹을 수 있는 물고기 발견
                if (sea[nR][nC] != 0 && sea[nR][nC] < shark)
                    fishList.push_back({ nR, nC });
                else
                    q.push({ nR, nC });
            }
        }

        // 현재 거리(level)에서 먹을 수 있는 물고기를 찾았다면
        if (!fishList.empty()) {
            sort(fishList.begin(), fishList.end());
            int dist = visited[fishList[0].first][fishList[0].second];
            return { dist, fishList[0].first, fishList[0].second };
        }
    }

    // 더 이상 먹을 수 있는 물고기가 없음
    return { 0, -1, -1 };
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    sea.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> sea[i][j];
            if (sea[i][j] == 9) {
                sR = i;
                sC = j;
                sea[i][j] = 0;
            }
        }
    }

    // 아기상어가 물고기를 찾는 과정 BFS 반복
    int totalTime = 0;
    while (1) {
        Result res = BFS(sR, sC);
        if (res.time == 0)
            break; // 더 이상 먹을 수 있는 물고기가 없음
        totalTime += res.time;

        meal++;
        if (meal == shark) {
            shark++;
            meal = 0;
        }

        sR = res.r;
        sC = res.c;
        sea[sR][sC] = 0;
    }

    cout << totalTime;

    return 0;
}
#endif
