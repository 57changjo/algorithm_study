#if 1

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

#define SIZE 21

int map[SIZE][SIZE] = { 0 };
int visited[SIZE][SIZE] = { 0 };
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int N;
int baby_shark_x, baby_shark_y;
int baby_shark_size = 2;
int eaten = 0;
int total_time = 0;

int bfs(int cur_shark_x, int cur_shark_y, int cur_shark_size) {

	std::fill(&visited[0][0], &visited[0][0] + SIZE * SIZE, 0); // visited 초기화

	std::queue<std::pair<int, int>> Q;
	std::vector<std::tuple<int, int, int>> fish_list;
	visited[cur_shark_x][cur_shark_y] = 1;

	Q.push({ cur_shark_x, cur_shark_y });

	while (!Q.empty()) {
		int x = Q.front().first;
		int y = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx >= 0 && nx < N) && (ny >= 0 && ny < N) && (visited[nx][ny] == 0) && (map[nx][ny] <= cur_shark_size)) {
				visited[nx][ny] = visited[x][y] + 1;
				Q.push({ nx, ny });

				if (map[nx][ny] != 0 && map[nx][ny] < cur_shark_size) {
					fish_list.push_back({ visited[nx][ny] - 1, nx, ny });
				}
			}
		}
	}

	if (fish_list.empty()) {
		return -1;
	}

	std::sort(fish_list.begin(), fish_list.end());

	int dist = std::get<0>(fish_list[0]);
	int nx = std::get<1>(fish_list[0]);
	int ny = std::get<2>(fish_list[0]);

	baby_shark_x = nx;
	baby_shark_y = ny;
	map[nx][ny] = 0;

	return dist;

}

int main(void) {

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			std::cin >> map[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 9) {
				baby_shark_x = i;
				baby_shark_y = j;
				map[i][j] = 0;
			}
		}
	}

	while (1) {

		int dist = bfs(baby_shark_x, baby_shark_y, baby_shark_size);

		if (dist == -1) break;

		total_time += dist;
		eaten++;

		if (eaten == baby_shark_size) {
			baby_shark_size++;
			eaten = 0;
		}
	}

	std::cout << total_time;

	return 0;
}
#endif
