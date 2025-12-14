#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>

using namespace std;

struct _node_t {
	int dr, dc;
}typedef node_t;

int map[100][70];
int visited[100][70];

int N, M;		//테두리 검증 사용해야함 -> 0이 의사결정에 쓰임

void inputdata(){
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

int dr[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
int dc[8] = { 0, 0, 1, -1, -1, 1, 1, -1 };

int solve() {
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j]) {
                int h = map[i][j];
                bool is_peak = true;
                queue<node_t> Q;
                Q.push({ i,j });
                visited[i][j] = 1;

                while (!Q.empty()) {
                    node_t cur = Q.front(); 
                    Q.pop();
                    for (int d = 0; d < 8; d++) {
                        int nr = cur.dr + dr[d];
                        int nc = cur.dc + dc[d];
                        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;

                        if (map[nr][nc] > h) {
                            is_peak = false; // 더 높은 칸 발견
                        }
                        if (!visited[nr][nc] && map[nr][nc] == h) {
                            visited[nr][nc] = 1;
                            Q.push({ nr,nc });
                        }
                    }
                }

                if (is_peak) cnt++;
            }
        }
    }
    return cnt;
}


int main() {
	(void)freopen("prob3.txt", "r", stdin);
	inputdata();
	cout << solve();

	return 0;
}
#endif
