#if 1

#include <iostream>
#include <algorithm>
#include <stdbool.h>

#define MAX 1299709

/*

10을 예시로

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 ,13 ,14 ,15 16

left = 10보다 작은 수들 중 가장 큰 소수
right = 10보다 큰 수들 중 가장 작은 소수

결과는 right - left 하면 끝

*/

bool is_prime[MAX + 1];

int main(void) {

	using namespace std;

	int T;

	fill(is_prime, is_prime + (MAX + 1), true);

	is_prime[0] = false, is_prime[1] = false; // 0이랑 1은 소수가 아님

	for (int i = 2; i * i <= MAX; i++) {

		if (is_prime[i] == true) {

			for (int j = i * i; j <= MAX; j += i) {

				is_prime[j] = false;
			}
		}
	}

	cin >> T;

	for (int i = 0; i < T; i++) {

		int k;
		int left, right;

		cin >> k;

		if (is_prime[k] == true) {
			cout << 0 << endl;
			continue;
		}

		left = k - 1;
		right = k + 1;

		while ((left > 0) && is_prime[left] == false) {
			left--;
		}

		while ((right < MAX) && is_prime[right] == false) {
			right++;
		}

		cout << right - left << endl;

	}

	return 0;
}

#endif
