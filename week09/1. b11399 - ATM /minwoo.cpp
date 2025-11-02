#include <iostream>
#include <algorithm>

int main(void) {

	int N = 0;
	int MINUTES[1001] = { 0 };
	int DP[1001] = { 0 };
	int TIME = 0;

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> MINUTES[i];
	}

	std::sort(MINUTES, MINUTES + N);

	DP[0] = MINUTES[0];

	for (int i = 1; i < N; i++) {
		DP[i] = (DP[i - 1] + MINUTES[i]);
	}

	for (int i = 0; i < N; i++) {
		TIME += DP[i];
	}

	std::cout << TIME;

	return 0;
}
