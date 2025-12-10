#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

#define MAX (200+2)
enum { Empty = 1 };

int R, C, N;
char map[MAX][MAX];
int map2[MAX][MAX];
int map3[MAX][MAX];

void inputData(void) {
    cin >> R >> C >> N;
    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            cin >> map[i][j];
            if (map[i][j] == 'O') {
                map2[i][j] = Empty;
                map2[i + 1][j] = Empty;
                map2[i - 1][j] = Empty;
                map2[i][j + 1] = Empty;
                map2[i][j - 1] = Empty;
            }
        }
    }

    for (int i = 1; i <= R; ++i) {
        for (int j = 1; j <= C; ++j) {
            if (map2[i][j] != Empty) {
                map3[i][j] = Empty;
                map3[i + 1][j] = Empty;
                map3[i - 1][j] = Empty;
                map3[i][j + 1] = Empty;
                map3[i][j - 1] = Empty;
            }
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b16918.txt", "r", stdin);
    inputData();
    
    if (N == 1) { // 입력 그대로
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                cout << map[i][j];
            }
            cout << '\n';
        }
    }
    else if ((N % 4) == 1) {
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (map3[i][j] == Empty) cout << '.';
                else cout << 'O';
            }
            cout << '\n';
        }
    }
    else if ((N % 4) == 3) { 
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                if (map2[i][j] == Empty) cout << '.';
                else cout << 'O';
            }
            cout << '\n';
        }
    }
    else { // N이 짝수면 모두 폭탄
        for (int i = 1; i <= R; ++i) {
            for (int j = 1; j <= C; ++j) {
                cout << 'O';
            }
            cout << '\n';
        }
    }
    
    return 0;
}
#endif
