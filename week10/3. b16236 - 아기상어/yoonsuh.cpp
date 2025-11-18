#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int map[20][20];
int dx[4] = {-1, 0, 0, 1}; 
int dy[4] = {0, -1, 1, 0};

struct Shark {
    int x, y, size = 2, eat = 0;
};

struct Fish {
    int x, y, dist;
};

bool cmp(Fish a, Fish b) {
    if (a.dist == b.dist) {
        if (a.x == b.x) return a.y < b.y;
        return a.x < b.x;
    }
    return a.dist < b.dist;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    Shark shark;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                shark.x = i;
                shark.y = j;
                map[i][j] = 0; 
            }
        }
    }

    int time = 0;

    while (true) {
        queue<pair<int,int>> q;
        int dist[20][20];
        for (int i = 0; i < N; i++)
            fill(dist[i], dist[i]+N, -1);

        dist[shark.x][shark.y] = 0;
        q.push({shark.x, shark.y});

        vector<Fish> fishList;

        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
                if (dist[nx][ny] != -1) continue;
                if (map[nx][ny] > shark.size) continue; 

                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});

              
                if (map[nx][ny] != 0 && map[nx][ny] < shark.size) {
                    fishList.push_back({nx, ny, dist[nx][ny]});
                }
            }
        }

        if (fishList.empty()) break; 

        sort(fishList.begin(), fishList.end(), cmp);
        Fish target = fishList[0];

        
        shark.x = target.x;
        shark.y = target.y;
        time += target.dist; 
        shark.eat++;
        map[target.x][target.y] = 0;


        if (shark.eat == shark.size) {
            shark.size++;
            shark.eat = 0;
        }
    }

    cout << time << "\n";
    return 0;
}
