#if 01
/*
* 블로그 풀이를 참고했습니다.
현재의 height에서 양옆의 최대 높이를 구해서
둘 중 작은 값에서 현재의 높이를 뺀 값을 계속해서 더하는 방식
단, 첫번째 값과 마지막 값은 제외하도록 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int W, H;
vector<int> height;

void inputData() {
	cin >> H >> W;
	height.assign(W, 0);
	for (int i = 0; i < W; i++) {
		cin >> height[i];
	}
}

int solve() {
	int rain = 0;

	for (int i = 1; i < W - 1; i++) {
		int left = 0, right = 0;
		for (int j = 0; j < i; j++) {
			left = max(left, height[j]);
		}
		for (int j = W - 1; j > i; j--) {
			right = max(right, height[j]);
		}
		rain += max(0, min(left, right) - height[i]);
	}

	return rain;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inputData();
	cout << solve();

	return 0;
}

#endif
