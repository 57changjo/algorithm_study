#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, D;
// tuple도 고려했는데, struct가 더 편함
struct Shortcut {
    int start;
    int end;
    int length;
};
vector<Shortcut> shortcuts;

void inputData() {
    cin >> N >> D;
	shortcuts.resize(N);
    for (int i = 0; i < N; i++) {
		cin >> shortcuts[i].start >> shortcuts[i].end >> shortcuts[i].length;
    }
}

int findShortestPath() {
    //// length 기준으로 오름차순 정렬, 비교함수를 직접 작성하는 방식 - 생각해보니 필요없음
    //sort(shortcuts.begin(), shortcuts.end(), 
    //    [](const Shortcut& a, const Shortcut& b) {
    //        return a.length < b.length;
    //    });

    vector<int> DP(D + 1, 0);
    for (int i = 1; i <= D; i++) {
        // 기본적으로는 이전 위치에서 1만큼 이동
        DP[i] = DP[i - 1] + 1;
        // 지름길이 있는지 확인
        for (int j = 0; j < N; j++) {
            if (i == shortcuts[j].end && shortcuts[j].start < i) {
                DP[i] = min(DP[i], DP[shortcuts[j].start] + shortcuts[j].length);
			}
		}
    }
    return DP[D];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    inputData();
    cout << findShortestPath();

    return 0;
}

#endif
