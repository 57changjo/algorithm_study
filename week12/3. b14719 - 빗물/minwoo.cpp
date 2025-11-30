#if 1

#include <iostream>
#include <algorithm>

// 물이 고일려면 양쪽에 벽이 있어야하구 물 타일 보다 벽이 높아야 가능

/*

예제 입력이 

4 4
3 0 1 4

i =             0  1  2  3
block_height = [3, 0, 1, 4]

아 현재 i번째 블록 왼쪽 오른쪽을 확인하고, 만약 양쪽이 나보다 높으면 물이 고이는 것?

왼쪽 최고 높이랑 오른쪽 최고 높이 구하고 그 둘중에 더 낮은 수랑 현재 블록이랑 빼서 물 높이 구하기

*/

int main(void) {

	using namespace std;

	int H, W;
	int block_height[500];
	int left_max[500];
	int right_max[500];
	int water = 0;

	cin >> H >> W;

	for (int i = 0; i < W; i++) {

		cin >> block_height[i];
	}
	
	left_max[0] = block_height[0];
	for (int j = 1; j < W; j++) {

		left_max[j] = max(block_height[j], left_max[j - 1]);
	}

	right_max[W - 1] = block_height[W - 1];
	for (int k = W - 2; k >= 0; k--) {

		right_max[k] = max(block_height[k], right_max[k + 1]);
	}

	for (int l = 0; l < W; l++) {

		int water_block = min(left_max[l], right_max[l]) - block_height[l];

		if (water_block > 0) {

			water += water_block;
		}
	}

	cout << water << endl;

	return 0;
}

#endif
