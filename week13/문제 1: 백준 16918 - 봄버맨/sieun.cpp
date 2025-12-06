#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int R, C, N;
vector<string> grid;
vector<string> temp_grid;
vector<string> even_grid;
vector<pair<int, int>> directions = { {-1,0}, {1,0}, {0,-1}, {0,1} };

void inputData() {
    string row;
    cin >> R >> C >> N;

    for(int i = 0; i < R; i++) {
        cin >> row;
        grid.push_back(row);
      //temp_grid.push_back(row);
   }

   // 짝수 초의 격자판 미리 생성
   even_grid.assign(R, string(C, 'O'));
}

void odd_solve() {
    // temp_grid를 grid로 매번 초기화
    temp_grid = grid;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 'O') {
            temp_grid[i][j] = 'z'; // 폭발 표시
                for (const auto& dir : directions) {
                    int dx = i + dir.first;
                    int dy = j + dir.second;
                    if (0 <= dx && dx < R && 0 <= dy && dy < C)
                        temp_grid[dx][dy] = 'z';
                }
            }
            else if (grid[i][j] == '.') {
                grid[i][j] = 'O';
            }
        }
    }
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (temp_grid[i][j] == 'z') {
                grid[i][j] = '.';
         }
        }
    }
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(nullptr);

    inputData();

    // N초 후의 격자판 출력
    if (N % 2 == 0) { // 짝수 초
        for (int i = 0; i < R; i++) {
         cout << even_grid[i] << "\n";
        }
    }
    else if (N == 1) { // 1초
        for (int i = 0; i < R; i++) {
            cout << grid[i] << "\n";
        }
   }
    else if (N % 4 == 1) { // 5, 9, 13, ...
        odd_solve();
        odd_solve();
        for (int i = 0; i < R; i++) {
            cout << grid[i] << "\n";
        }
    }   
    else if (N % 4 == 3) { // 3, 5, 11, ...
        odd_solve();
        for (int i = 0; i < R; i++) {
            cout << grid[i] << "\n";
        }
   }

    return 0;
}

#endif
