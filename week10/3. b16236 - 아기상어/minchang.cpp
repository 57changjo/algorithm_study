#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

int N;
int map[20][20];

int shark_r, shark_c;
int shark_size = 2;
int eat_count = 0;
int total_time = 0;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

struct Target {
    int r, c, dist;
};


bool compareTargets(Target a, Target b) {
    if (a.dist != b.dist) {
        return a.dist < b.dist;
    }
    if (a.r != b.r) {
        return a.r < b.r;
    }
    return a.c < b.c;
}

bool findAndEatFish(void) {
    int dist[20][20];
    memset(dist, -1, sizeof(dist));

    queue<pair<int, int>> q;
    vector<Target> candidates;

    q.push({ shark_r, shark_c });
    dist[shark_r][shark_c] = 0;

    while (!q.empty()) {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= N || dist[nr][nc] != -1) {
                continue;
            }

            if (map[nr][nc] > shark_size) {
                continue;
            }

            dist[nr][nc] = dist[r][c] + 1;
            q.push({ nr, nc });

            if ((map[nr][nc] > 0) && (map[nr][nc] < shark_size)) {
                candidates.push_back({ nr, nc, dist[nr][nc] });
            }
        }
    }

    if (candidates.empty()) {
        return false;
    }

    sort(candidates.begin(), candidates.end(), compareTargets);

    Target best = candidates[0];

    total_time += best.dist;
    eat_count++;
    map[best.r][best.c] = 0;
    shark_r = best.r;
    shark_c = best.c;

    if (eat_count == shark_size) {
        shark_size++;
        eat_count = 0;
    }

    return true;
}

void inputData(void) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark_r = i;
                shark_c = j;
                map[i][j] = 0;
            }
        }
    }
}

void solve(void) {
    while (findAndEatFish()) {
    }

    cout << total_time;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b16236.txt", "r", stdin);

    inputData();
    solve();

    return 0;
}
