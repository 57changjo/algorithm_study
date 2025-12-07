
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int R, C, N;
vector<string> grid;

// 상, 하, 좌, 우
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void dataInput(void) {
    cin >> R >> C >> N;
    grid.resize(R);
    for (int i = 0; i < R; i++) {
        cin >> grid[i];
    }
}

// 현재 그리드의 폭탄을 기준으로 폭발을 일으키고 다음 상태를 반환
vector<string> explode(vector<string>& currentGrid) {
    // 모든 칸이 폭탄
    vector<string> nextGrid(R, string(C, 'O'));

	// 원래 있던 폭탄, 그 주변 칸 파괴
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (currentGrid[i][j] == 'O') {
                nextGrid[i][j] = '.';

                for (int k = 0; k < 4; k++) {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    if (ny >= 0 && ny < R && nx >= 0 && nx < C) {
                        nextGrid[ny][nx] = '.';
                    }
                }
            }
        }
    }
    return nextGrid;
}

void solve(void) {
    if (N == 1) {
        for (string& row : grid) cout << row << "\n";
        return;
    }

    if (N % 2 == 0) {
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cout << 'O';
            }
            cout << "\n";
        }
        return;
    }

    // 3초 시점
    vector<string> result1 = explode(grid);

    if (N % 4 == 3) {
        // N % 4 == 3 이면 한 번 폭발
        for (string& row : result1) cout << row << "\n";
    }
    else {
        // N % 4 == 1 이면 한 번 더 폭발
        vector<string> result2 = explode(result1);
        for (string& row : result2) cout << row << "\n";
    }
}

int main(void) {
    //(void)freopen("b16918.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dataInput();
    solve();

    return 0;
}
