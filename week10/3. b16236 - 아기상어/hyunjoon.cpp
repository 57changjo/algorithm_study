#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_N (20)

class node {
public:
	int r = 0, c = 0;
};
node Q[MAX_N*MAX_N];



int map[MAX_N][MAX_N];

int N;
int shark = 2;
int sr = 0, sc = 0;
int eat = 0;

int bfs() {
	int dr[4] = { -1, 0, 0, 1 };
	int dc[4] = { 0, -1, 1, 0 };
	node current = { sr,sc };
	int front = 0, rear = 0;
	int nr, nc;

	int visited[MAX_N][MAX_N] = { 0 };
	visited[sr][sc] = 1;
	
	Q[rear++] = { sr,sc };

	while (rear != front) {
		current = Q[front++];
		for (int i = 0; i < 4; ++i) {
			nr = current.r + dr[i];
			nc = current.c + dc[i];
			if (nr<0 || nr>=N || nc<0 || nc>=N)
				continue;
			if (visited[nr][nc])
				continue;
			if (map[nr][nc] > shark)
				continue;
			visited[nr][nc] = visited[current.r][current.c] + 1;
			Q[rear++] = { nr, nc };
			if (map[nr][nc] < shark && map[nr][nc]>0) {
				eat++;
				map[nr][nc] = 0;
				if (eat == shark) {
					shark++;
					eat = 0;
				}
				cout << visited[nr][nc] << '\n';
				return visited[nr][nc];
			}
		}
	}
	return 0;
}

int main(void) {
	int sr = 0, sc = 0;
	(void)freopen("prob3.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				sr = i;
				sc = j;
				map[i][j] = 0;		//상어 있던 자리 초기화	
			}
		}
	}
	int time = 0;
	int cnt = 0;
	while (1) {
		int a = bfs();
		if (a) {
			time += a;
		}
		else 
			break;
	}

	cout << time;
		//<< '\n' << "cnt " << cnt;
	
}
