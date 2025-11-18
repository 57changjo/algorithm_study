#if 1

#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {

	int stairs_cnt;

	std::cin >> stairs_cnt;
	std::vector <int> stairs(stairs_cnt);
	std::vector <int> dp(stairs_cnt);
	
	for (int i = 0; i < stairs_cnt; i++) {
		std::cin >> stairs[i];
	}

	dp[0] = stairs[0];
	dp[1] = dp[0] + stairs[1];
	dp[2] = std::max((stairs[0] + stairs[2]), (stairs[1] + stairs[2]));

	for (int i = 3; i < stairs_cnt; i++) {
		
		// i - 1 스킵하고 i - 2밟고 현재 i 밟을 때 (연속으로 두 번) VS i - 3이 이전 마지막으로 밟은 곳에서 i - 2 건너뛰고 i - 1 바로 이전 계단 밟고 현재 계단에 왔을 때 
		dp[i] = std::max((dp[i - 2] + stairs[i]), (dp[i - 3] + stairs[i - 1] + stairs[i]));
	}

	std::cout << dp[stairs_cnt - 1];

	return 0;
}
#endif
