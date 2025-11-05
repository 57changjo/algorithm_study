#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string gears[5]; // N: 0, S: 1
int K;

void inputData(void) {
	for (int i = 1; i <= 4; i++) {
		cin >> gears[i];
	}

	cin >> K;
}

void rotateGear(int gearNum, int dir) {
	if (dir == 0) return;

	if (dir == 1) { // clock
		gears[gearNum] = gears[gearNum].back() + gears[gearNum].substr(0, 7);
	}
	else { // reverse
		gears[gearNum] = gears[gearNum].substr(1, 7) + gears[gearNum].front();
	}
}

void rotation(int startGear, int startDir) {
	// 회전 결과에 따라 회전 하는게 아닌 동시에 회전 방향을 정해야 함
	int rotationDirs[5] = { 0, 0, 0, 0, 0 }; // 0: no rotate, 1: clock, -1: reverse
	rotationDirs[startGear] = startDir;

	// 오른쪽
	// 3시: 2, 9시: 6
	for (int i = startGear; i < 4; ++i) {
		if (gears[i][2] != gears[i + 1][6]) {
			// 역방향 회전
			rotationDirs[i + 1] = -rotationDirs[i];
		}
		else {
			break;
		}
	}

	// 왼쪽
	// 9시: 6, 3시: 2
	for (int i = startGear; i > 1; --i) {
		if (gears[i][6] != gears[i - 1][2]) {
			rotationDirs[i - 1] = -rotationDirs[i];
		}
		else {
			break;
		}
	}

	// 회전 적용
	for (int i = 1; i <= 4; ++i) {
		rotateGear(i, rotationDirs[i]);
	}
}

int score(void) {
	int tot = 0;

	if (gears[1][0] == '1') tot += 1;
	if (gears[2][0] == '1') tot += 2;
	if (gears[3][0] == '1') tot += 4;
	if (gears[4][0] == '1') tot += 8;

	return tot;
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	//(void)freopen("b10162.txt", "r", stdin);
	inputData();

	int gearNum, dir;

	for (int i = 0; i < K; ++i) {
		cin >> gearNum >> dir;
		rotation(gearNum, dir);
	}

	cout << score();

	return 0;
}
