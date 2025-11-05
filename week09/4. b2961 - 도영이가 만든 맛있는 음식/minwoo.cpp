#if 1

#include <iostream>
#include <algorithm>
#include <cmath>

// 완전탐색 가능할 것 같음
int N;
int TOTAL;
int SOUR[10];
int BITTER[10];
int ANSWER = 1000000000;

void dfs(int idx, int sour, int bitter, bool used) {
	if (idx == N) {
		if (used) ANSWER = std::min(ANSWER, abs(sour - bitter));
		return;
	}

	dfs(idx + 1, sour * SOUR[idx], bitter + BITTER[idx], true);

	dfs(idx + 1, sour, bitter, used);
}

int main(void) {

	std::cin >> N;

	for (int i = 0; i < N; i++) {
		std::cin >> SOUR[i] >> BITTER[i];
	}

	dfs(0, 1, 0, false);

	std::cout << ANSWER;

	return 0;
}
#endif
