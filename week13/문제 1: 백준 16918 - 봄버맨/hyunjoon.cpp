#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int R, C, N;
char bomb_org[201][201];
char bomb_cp[201][201];
enum bomb {
	bomb = 'O',
	blank = '.'
};

void inputdata() {
	cin >> R >> C >> N;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> bomb_org[i][j];
		}
	}
}

void printdata() {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << bomb_cp[i][j];
		}
		cout << '\n';
	}
}

void solve(int time) {
	if (time == 1) {
		return;
	}

	solve(time - 1);

	for (int i = 1; i <= R; i++) {						// 채우기
		for (int j = 1; j <= C; j++) {
			bomb_cp[i][j] = bomb;
		}
	}

	if (time % 2) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if (bomb_org[i][j] == bomb) {
					bomb_cp[i][j] = blank;
					bomb_cp[i - 1][j] = blank;
					bomb_cp[i][j - 1] = blank;	
					bomb_cp[i + 1][j] = blank;
					bomb_cp[i][j + 1] = blank;
				}
			}
		}
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				bomb_org[i][j] = bomb_cp[i][j];
			}
		}
	}
}

int main(void) {
	(void)freopen("b16918.txt", "r", stdin);
	inputdata();
	if (N == 1) {
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				cout << bomb_org[i][j];
			}
			cout << '\n';
		}
		return 0;
	}
	solve(N);
	printdata();

	return 0;
}



#endif
