#if 1

#include <iostream>
#include <algorithm>

int main(void) {

	using namespace std;

	int T, n;

	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> n;

		int a, b, c;
		int result = 0;

		// 1 * a + 2 * b + 3 *c = n
		// 1을 a개 씀, 2를 b개 씀, 3을 c개 쓰면 n이 된다

		for (c = 0; c <= n / 3; c++) {

			int rem_after_c = n - 3 * c;

			for (b = 0; b <= rem_after_c / 2; b++) {

				int rem_after_b = rem_after_c - 2 * b;
				a = rem_after_b;

				if (a >= 0) {
					result++;
				}
			}
		}
		cout << result << endl;
	}

	return 0;
}

#endif
