#if 0

#include <iostream>
#include <algorithm>

#define SIZE 200000

int main(void) {

	int N;
	int C;
	int houses[SIZE];

	std::cin >> N >> C;

	for (int i = 0; i < N; i++) {
		std::cin >> houses[i];
	}

	std::sort(houses, houses + N);

	int low = 1;
	int high = houses[N - 1] - houses[0];
	int dist = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		int count = 1;
		int last = houses[0];

		for (int i = 1; i < N; i++) {

			if (houses[i] - last >= mid) {
				count++;
				last = houses[i];
			}
		}

		if (count >= C) {
			dist = mid;
			low = mid + 1;
		}

		else {
			high = mid - 1;
		}
	}

	std::cout << dist;

	return 0;
}

#endif
