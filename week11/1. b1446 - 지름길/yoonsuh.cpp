#include <iostream>   
#include <vector>     
#include <algorithm>  
#include <utility>    // pair 사용
#include <climits>    // INT_MAX 사용 가능
//#include <bits/stdc++.h> 이거 하나로 밑에 있는걸 다 사용할 수 있다고 합니다!
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <queue>
//#include <stack>
//#include <algorithm>
//#include <cmath>
//#include <cstring>
//#include <set>
//#include <climits>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;

    vector<pair<int,int>> shortCut[10001]; // [시작점] → (도착점, 거리)

    for (int i = 0; i < N; i++) {
        int s, e, l;
        cin >> s >> e >> l;

        if (e > D) continue;        // 도착점이 D를 넘으면 무시
        if (e - s <= l) continue;   // 일반 도로보다 길면 무시

        shortCut[s].push_back(make_pair(e, l));
    }

    vector<int> dist(D + 1, INT_MAX);
    dist[0] = 0; // 시작점

    for (int i = 0; i <= D; i++) {
        if (i > 0)
            dist[i] = min(dist[i], dist[i - 1] + 1);

        for (int j = 0; j < shortCut[i].size(); j++) {
            int e = shortCut[i][j].first;
            int l = shortCut[i][j].second;
            if (e <= D)
                dist[e] = min(dist[e], dist[i] + l);
        }
    }

    cout << dist[D] << "\n";
    return 0;
}
