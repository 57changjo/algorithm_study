#if 01
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

// 가장 직관적인 풀이 - O(N^2)
int solve1() {
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

// 투 포인터 풀어 - O(N)
int solve2() {
	int left = 0, right = W - 1;
	int left_max = 0, right_max = 0;
	int rain = 0;

	while (left < right) {
		// 왼쪽 - 더 낮은 쪽을 먼저
		if (height[left] <= height[right]) {
			if (height[left] >= left_max) {
				left_max = height[left];
			}
			else {
				rain += left_max - height[left];
			}
			left++;
		}
		// 오른쪽
		else {
			if (height[right] >= right_max) {
				right_max = height[right];
			}
			else {
				rain += right_max - height[right];
			}
			right--;
		}
	}

	return rain;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inputData();
	cout << solve2();

	return 0;
}

#endif
