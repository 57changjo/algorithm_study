#if 1

#include <iostream>
#include <algorithm>

#define SIZE 100001

int main(void) {

	using namespace std;

	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	int RGB_to_NUM[SIZE];
	int temp[SIZE];
	int ans = 1e9;
	int cnt = 0;
	char letter;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> letter;

		if (letter == 'R') RGB_to_NUM[i] = 0;
		else if (letter == 'G') RGB_to_NUM[i] = 1;
		else RGB_to_NUM[i] = 2;
	}

	// 0: R, 1: G, 2: B
	for (int i = 0; i < 3; i++) {
		copy(RGB_to_NUM, RGB_to_NUM + N, temp);
		cnt = 0;

		for (int j = 0; j <= N - 3; j++) {
			int k = (i - temp[j] + 3) % 3;
			if (k == 0) continue;

			temp[j] = (temp[j] + k) % 3;
			temp[j + 1] = (temp[j + 1] + k) % 3;
			temp[j + 2] = (temp[j + 2] + k) % 3;

			cnt += k;
		}

		if (temp[N - 2] == i && temp[N - 1] == i) {
			ans = min(ans, cnt);
		}
	}

	if (ans == 1e9) cout << -1;
	else cout << ans;

	return 0;
}
#endif
