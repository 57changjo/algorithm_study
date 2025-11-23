#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX (500+1)

int N, M;
vector<vector<int>> map(MAX, vector<int>(MAX));

void inputData(void) {
    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }
}

void makeMap(void) {
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][k] && map[k][j]) {
                    map[i][j] = 1;
                }
            }
        }
    }
}

int counting(void) {
    int total = 0;
    for (int i = 1; i <= N; i++) {
        int cnt = 0;
        for (int j = 1; j <= N; j++) {
            if (i == j) continue;
            if (map[i][j] || map[j][i]) cnt++;
        }
        if (cnt == N - 1) total++;
    }
    return total;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b2458.txt", "r", stdin);
    inputData();

    makeMap();
    cout << counting();
    return 0;
}
#endif
