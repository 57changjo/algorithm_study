
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

struct rc {
    int r, c;
};

int N, M;
int minCityChickenDist = INT_MAX;

vector<rc> houses;
vector<rc> chickens;
vector<rc> selected;

void dataInput(void) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int type;
            cin >> type;
            if (type == 1) {
                houses.push_back({ i + 1, j + 1 });
            }
            else if (type == 2) {
                chickens.push_back({ i + 1, j + 1 });
            }
        }
    }
}

// 거리 계산 함수 (절댓값 합)
int getDist(const rc& a, const rc& b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

// 현재 선택한 치킨집들에 대해서 도시의 치킨 거리를 구하기
void getTotDist(void) {
    int totDist = 0;

    // 모든 집에 대해
    for (auto& h : houses) {
        int minDist = INT_MAX;

        // 선텍힌 치킨집들 중에서 가장 가까운 치킨집 거리 구하기
        for (auto& c : selected) {
            int d = getDist(h, c);
            if (d < minDist) {
                minDist = d;
            }
        }
        totDist += minDist;
    }

    if (totDist < minCityChickenDist) {
        minCityChickenDist = totDist;
    }
}

// 조합구하기
// index: 현재 선택한 치킨집, count: 그 수
void DFS(int idx, int count) {
    if (count == M) {
        getTotDist();
        return;
    }

    // 남은 치킨집들 선택
    for (int i = idx; i < chickens.size(); i++) {
        selected.push_back(chickens[i]);

        DFS(i + 1, count + 1);

        // 복구
        selected.pop_back();
    }
}

void solve(void) {
    DFS(0, 0);

    cout << minCityChickenDist;
}

int main(void) {
    //(void)freopen("b15686.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dataInput();
    solve();

    return 0;
}
