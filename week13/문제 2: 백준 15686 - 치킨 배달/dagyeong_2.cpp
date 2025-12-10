// 치킨거리
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N, M;
vector<pair<int, int>> houses;
vector<pair<int, int>> chickens;
int answer = INT_MAX;

int distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void inputData(void) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int c = 0;
            cin >> c;
            if (c == 1) houses.push_back({ i, j });
            else if (c == 2) chickens.push_back({ i, j });
        }
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b15686.txt", "r", stdin);
    inputData();

    int num = chickens.size();

    // 치킨집 중 M개 고르기
    vector<bool> select(num, false);
    fill(select.begin(), select.begin() + M, true); // 앞에서부터 M개 true, 나머지(치킨집 수) false인 벡터 생성
    
    do {
        vector<pair<int, int>> chickenList;
        for (int i = 0; i < num; ++i) {
            if (select[i]) {
                chickenList.push_back(chickens[i]);
            }
        }
        // 집 마다 돌면서 치킨거리 찾기
        int total = 0;
        for (int i = 0; i < houses.size(); ++i) {
            int dist = INT_MAX;
            for (int j = 0; j < M; ++j) {
                dist = min(distance(chickenList[j], houses[i]), dist);
            }
            total += dist;
        }
        answer = min(answer, total);
    } while (prev_permutation(select.begin(), select.end()));

    cout << answer << endl;
    return 0;
}
#endif
