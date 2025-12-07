// 문제는 이해를 했으나 각각 구현부분에서는 GPT 사용하였습니다.. -> 아직 구현 부분 좀더 공부 필요.

#include <iostream>
#include <string>
using namespace std;

#define MAX 200+1

int R, C, N; // 초기화 귀찮으니 전역으로 초기화
char board[MAX][MAX]; 
char temp[MAX][MAX];

// 방향(상,하,좌,우)
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void read_input() {
    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < C; j++) {
            board[i][j] = row[j];   // '.' 또는 'O'
        }
    }
}

// oldBoard의 폭탄을 터뜨려 newBoard를 만든다.
void explode(char oldBoard[MAX][MAX], char newBoard[MAX][MAX]) {
    // 기본은 전체 폭탄으로 채움
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            newBoard[i][j] = 'O';

    // 폭발 처리
    for (int y = 0; y < R; y++) {
        for (int x = 0; x < C; x++) {
            if (oldBoard[y][x] == 'O') { // 폭발물이 있는것을 조건으로 확인해서

                newBoard[y][x] = '.'; // 터트리고 .으로 채워넣기

                for (int d = 0; d < 4; d++) { // 상,하,좌,우 체킹
                    int ny = y + dy[d];
                    int nx = x + dx[d];
                    if (0 <= ny && ny < R && 0 <= nx && nx < C)
                        newBoard[ny][nx] = '.'; //폭탄일 시에 처리 후 . 처리
                }
            }
        }
    }
}

void simulate() {
    if (N == 1) return;                 // 초기 상태 그대로
    if (N % 2 == 0) {                   // 짝수초 -> 전체 폭탄 (1+1 초 3+1초 => 다 짝수일떄는 다 폭탄으로 가득)
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++) // 폭탄 가득 채우기
                board[i][j] = 'O';
        return;
    }

    // 3초: 첫 폭발
    char first[MAX][MAX];
    explode(board, first);

    // 5초: 두번째 폭발 (2초떄 폭탄으로 가득 찼으므로)
    char second[MAX][MAX];
    explode(first, second);

    // N % 4 == 3 → 3초 폭발 상태
    // N % 4 == 1 → 5초 폭발 상태
    if (N % 4 == 3) {
        // first → board
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                board[i][j] = first[i][j];
    }
    else {
        // second → board
        for (int i = 0; i < R; i++)
            for (int j = 0; j < C; j++)
                board[i][j] = second[i][j];
    }
}

void print_board() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++)
            cout << board[i][j];
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    read_input();
    simulate();
    print_board();
    return 0;
}
