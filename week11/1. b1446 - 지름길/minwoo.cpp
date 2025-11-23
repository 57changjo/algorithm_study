#if 0

#include <iostream>
#include <algorithm>
#include <climits>

#define SIZE 10001

int main(void) {

	int N;
	int D;

	int start[12];
	int end[12];
	int length[12];
	int dp[SIZE];

	std::cin >> N >> D;

	for (int i = 0; i < N; i++) {
		std::cin >> start[i] >> end[i] >> length[i];
	}

	for (int i = 0; i <= D; i++) {
		dp[i] = INT_MAX;
	}

	dp[0] = 0;

	for (int i = 0; i < D; i++) {
		dp[i + 1] = std::min(dp[i] + 1, dp[i + 1]);
		for (int j = 0; j < N; j++) {
			if (start[j] == i && end[j] <= D) {
				dp[end[j]] = std::min(dp[end[j]], dp[i] + length[j]);
			}
		}
	}

	std::cout << dp[D];

	return 0;
}

#endif
