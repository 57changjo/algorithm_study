#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> belt;
vector<bool> robot;   // 0~N-1 까지만 필요 (내리는 곳에서 항상 내림)

void inputData() {
	cin >> N >> K;
	belt.assign(2 * N, 0);
	robot.assign(N, 0);
	for (int i = 0; i < 2 * N; i++) {
		cin >> belt[i];
	}
}

int solve() {
	int step = 1;

	while (1) {
		// 1. 벨트 회전 - 내구성 변화 x
		// 1.1 벨트 한 칸 - 오른쪽 회전, 왼쪽 회전 잘 생각하기
		rotate(belt.rbegin(), belt.rbegin() + 1, belt.rend());
		// 1.2 로봇 한 칸
		rotate(robot.rbegin(), robot.rbegin() + 1, robot.rend());
		robot[N - 1] = 0;     // 내리는 위치는 항상 비워진다

		// 2. 로봇 이동 - 내구성 변화 o
		// 2.1 로봇 한 칸
		for (int i = N - 2; i >= 0; i--) {
			if (robot[i] == 1 && robot[i+1] == 0 && belt[i+1] > 0) {
				robot[i + 1] = 1;
				robot[i] = 0;
				belt[i + 1]--;
			}
		}
		// 2.2 로봇 내리기 - N-1
		robot[N - 1] = 0;

		// 3. 로봇 올리기 - 0
		if (belt[0] > 0) {
			robot[0] = 1;
			belt[0]--;
		}

		// 4. 내구도 확인
		int problem = 0;
		for (int i = 0; i < 2 * N; i++) {
			if (belt[i] == 0)
				problem++;
		}
		
		if (problem >= K)
			break;

		// 5. 반복
		step++;
	}

	return step;
}

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr);

	inputData();
	cout << solve();

	return 0;
}
#endif
