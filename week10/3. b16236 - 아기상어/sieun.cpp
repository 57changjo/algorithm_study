// 미완 - 수정 예정
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

Result BSF(int sR, int sC) {
    queue < Node> q;
	q.push({ sR, sC });
	visited[sR][sC] = 1;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            nR = curr.r + dr[dir];
            nC = curr.c + dc[dir];

            if (nR < 0 || nR >= N || nC < 0 || nC >= N)
                continue;
            if (visited[nR][nC] != 0)
                continue;
			if (sea[nR][nC] > shark)
				continue;
            if (sea[nR][nC] != 0 && sea[nR][nC] < shark)
                return { visited[curr.r][curr.c], nR, nC }; // 먹을 수 있는 물고기 발견

            visited[nR][nC] = visited[curr.r][curr.c] + 1;
            q.push({ nR, nC });
		}
    }
    return { 0, -1, -1 }; // 더 이상 먹을 수 있는 물고기가 없음
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    sea.assign(N, vector<int>(N, 0));
    visited.assign(N, vector<int>(N, 0));
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
        visited.assign(N, vector<int>(N, 0));
        Result res = BSF(sR, sC);
        int time = res.time;
        if (time == 0)
            break; // 더 이상 먹을 수 있는 물고기가 없음
        totalTime += time;
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
