#if 1

#include <iostream>
#include <algorithm>
#include <vector>


int main(void) {

	int N;

	std::cin >> N;

	std::vector <int> T(N + 1); // i번째 날 상담 할 때 걸리는 기간
	std::vector <int> P(N + 1); // i번째 날 상담 할 때 받는 이익
	std::vector <int> dp(N + 2); // 퇴사일은 N + 1이니깐 거기에 1 더하기

	for (int i = 1; i <= N; i++) {

		std::cin >> T[i] >> P[i];
	}

	for (int j = 1; j <= N; j++) {

		// 상담 안 함
		dp[j + 1] = std::max(dp[j + 1], dp[j]);

		if (j + T[j] <= N + 1) {

			//상담 함
			dp[j + T[j]] = std::max(dp[j + T[j]], dp[j] + P[j]);
		}
	}

	std::cout << dp[N + 1];

	return 0;
}
#endif
