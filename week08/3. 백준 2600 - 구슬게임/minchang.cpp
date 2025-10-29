#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstring>

int b[3];
int tc = 5;
int k[5][2];

// dp[k1][k2]일 때 현재 플레이어 승리: 1, 패배: 0
int dp[501][501];

void inputData(void) {
	std::cin >> b[0] >> b[1] >> b[2];
	for (int i = 0; i < tc; i++) {
		std::cin >> k[i][0] >> k[i][1];
	}
}

void printData(void) {
	std::cout << b[0] << " " << b[1] << " " << b[2] << "\n";
	for (int i = 0; i < tc; i++) {
		std::cout << k[i][0] << " " << k[i][1] << "\n";
	}
}


// return 승리 여부
int solve(int k1, int k2) {
	// dp 검사
	if (dp[k1][k2] != -1) {
		return dp[k1][k2];
	}

	// k1
	for (int i = 0; i < 3; i++) {
		if (k1 >= b[i]) {
			// b[i]개를 가져갔을 때 상대방이 패배하면, 나는 승리
			if (solve(k1 - b[i], k2) == 0) {
				dp[k1][k2] = 1;
				return 1;
			}
		}
	}

	// k2
	for (int i = 0; i < 3; i++) {
		if (k2 >= b[i]) {
			// b[i]개를 가져갔을 때 상대방이 패배하면, 나는 승리
			if (solve(k1, k2 - b[i]) == 0) {
				dp[k1][k2] = 1;
				return 1;
			}
		}
	}

	// lose
	dp[k1][k2] = 0;
	return 0;
}

int main(void) {
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);

	//(void)freopen("b2600.txt", "r", stdin);
	inputData();
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < tc; i++) {
		if (solve(k[i][0], k[i][1]) == 1) {
			std::cout << "A\n";
		}
		else {
			std::cout << "B\n";
		}
	}

	return 0;
}
