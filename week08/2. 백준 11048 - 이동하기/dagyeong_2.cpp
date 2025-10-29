#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<int>> DP;

void inputData(void) {
    cin >> N >> M;

    map.resize(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }
}

void printData(vector<vector<int>>& arr) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; j++) {
            cout << arr[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

int main(void) {
    //(void)freopen("b11048.txt", "r", stdin);
    inputData();
    //printData(map);

    DP.resize(N + 1, vector<int>(M + 1));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; j++) {
            if ((DP[i - 1][j] > DP[i - 1][j - 1]) && (DP[i - 1][j] > DP[i][j - 1])) {
                DP[i][j] = DP[i - 1][j] + map[i][j];
            }
            else if (DP[i - 1][j - 1] > DP[i][j - 1]) {
                DP[i][j] = DP[i - 1][j - 1] + map[i][j];
            }
            else {
                DP[i][j] = DP[i][j - 1] + map[i][j];
            }
        }
    }
    //printData(DP);

    cout << DP[N][M] << endl;
    return 0;
}

#endif
