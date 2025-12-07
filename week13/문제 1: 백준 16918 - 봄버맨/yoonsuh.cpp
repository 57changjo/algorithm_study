#include <bits/stdc++.h>
using namespace std;

int R, C, N;
vector<string> board;

vector<string> explode(const vector<string>& b) {
    vector<string> res(R, string(C, 'O'));
    int dx[4] = {1, -1, 0, 0};
    int dy[4] = {0, 0, 1, -1};

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (b[i][j] == 'O') {
                res[i][j] = '.';
                for (int k = 0; k < 4; k++) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && ny >= 0 && nx < R && ny < C)
                        res[nx][ny] = '.';
                }
            }
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> R >> C >> N;
    board.resize(R);
    for (int i = 0; i < R; i++) cin >> board[i];

    if (N == 1) {
        // 초기 상태 그대로 출력
    } else if (N % 2 == 0) {
        // 모든 칸 폭탄
        for (int i = 0; i < R; i++) board[i] = string(C, 'O');
    } else if (N % 4 == 3) {
        // 3초 후 (첫 폭발)
        board = explode(board);
    } else if (N % 4 == 1) {
        // 5초 후 (두 번째 폭발)
        board = explode(explode(board));
    }

    for (int i = 0; i < R; i++)
        cout << board[i] << '\n';
}
