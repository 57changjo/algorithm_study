#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX (1500000+2)

int N;
vector<vector<int>> schedule(MAX, vector<int>(2));
vector<int> earning(MAX); //earning[i]: i 전날까지의 최대 비용

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //(void)freopen("b15486.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> schedule[i][0] >> schedule[i][1]; // 시간, 비용
    }

    for (int i = 1; i <= N; ++i) {
        earning[i] = max(earning[i - 1], earning[i]); //earning[i]를 max로

        int nextDay = i + schedule[i][0];
        if (nextDay > N + 1) continue;

        int newEarn = earning[i] + schedule[i][1];
        earning[nextDay] = max(earning[nextDay], newEarn);
    }

    cout << max(earning[N], earning[N + 1]);
    return 0;
}
