#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#define MAX (1000 + 1)

int N;
int M;
int MAP[MAX][MAX];
int DP[MAX][MAX];

void inputData(void) {
    std::cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            std::cin >> MAP[i][j];
        }
	}
}

void printData(void) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            std::cout << MAP[i][j] << ' ';
        }
        std::cout << '\n';
	}
}

void solve(void) {
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            DP[i][j] = std::max({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]}) + MAP[i][j];
        }
	}

    std::cout << DP[N][M];
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //(void)freopen("b11048.txt", "r", stdin);
    inputData();
	//printData();
    solve();

    return 0;
}
