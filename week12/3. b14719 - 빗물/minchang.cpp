#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int H, W;
vector<int> map;

void inputData(void) {
    cin >> H >> W;
    map.resize(W);
    for (int i = 0; i < W; i++) {
        cin >> map[i];
    }
}

int solve(void) {
    int tot = 0;

    // 첫 열, 마지막 열은 물 고일 수 X
    for (int i = 1; i < W - 1; i++) {
        int leftMax = 0;
        int rightMax = 0;

        // 왼쪽에서 가장 높은 벽 찾기
        for (int j = 0; j < i; j++) {
            leftMax = max(leftMax, map[j]);
        }

        // 오른쪽에서 가장 높은 벽 찾기
        for (int j = i + 1; j < W; j++) {
            rightMax = max(rightMax, map[j]);
        }

        // 둘 중 낮은 높이가 최대
        int maxHeight = min(leftMax, rightMax);

		// 그 차이가 차는 물의 높이
        if (maxHeight > map[i]) {
            tot += (maxHeight - map[i]);
        }
    }

    return tot;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // (void)freopen("b14719.txt", "r", stdin);

    inputData();
    cout << solve();

    return 0;
}
