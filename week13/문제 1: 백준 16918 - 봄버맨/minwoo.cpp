#if 1

#include <iostream>
#include <algorithm>

#define SIZE 200

int R, C, N;

char map_start[SIZE][SIZE];
char map_after1[SIZE][SIZE];
char map_after2[SIZE][SIZE];

/*

t = 0 제일 처음에 일부 칸에 폭탄을 설치한다
t = 1 아무것도 안 함 (초기 상태 동일)
t = 2 폭탄이 설치되어 있지 않은 칸에 폭탄을 설치함
t = 3 제일 처음에 설치된 폭탄이 모두 폭발함
t = 4 또 전체 폭탄 설치
t = 5 t = 2 일 때 설치한 폭탄 폭발

*/

using namespace std;

void input(void) {

	cin >> R >> C >> N;

	for (int i = 0; i < R; i++) {
		cin >> map_start[i];
	}
}

void fill(char map[SIZE][SIZE]) {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			map[i][j] = 'O';
		}
	}
}

void print_map(char map[SIZE][SIZE]) {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

void print_full(void) {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << 'O';
		}
		cout << '\n';
	}
}

void solve(char map_before[SIZE][SIZE], char map_after[SIZE][SIZE]) {

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map_before[i][j] == 'O') {
				map_after[i][j] = '.';
				if (i > 0) map_after[i - 1][j] = '.';
				if (i < R - 1) map_after[i + 1][j] = '.';
				if (j > 0) map_after[i][j - 1] = '.';
				if (j < C - 1) map_after[i][j + 1] = '.';
			}
		}
	}
}

int main(void) {

	input();

	fill(map_after1);
	solve(map_start, map_after1);

	fill(map_after2);
	solve(map_after1, map_after2);

	if (N == 1) print_map(map_start);
	else if (N % 2 == 0) print_full();
	else if (N % 4 == 3) print_map(map_after1);
	else print_map(map_after2);

	return 0;
}

#endif 
