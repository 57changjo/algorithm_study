#if 1

#include <iostream>
#include <algorithm>

int main(void) {

	int T;
	int BUTTONS[3] = { 300, 60, 10 };
	int COUNT[3] = { 0 };

	std::cin >> T;

	if (T % 10 != 0) {

		std::cout << -1;
		return 0;
	}

	for (int i = 0; i < 3; i++) {
		COUNT[i] = T / BUTTONS[i];
		T %= BUTTONS[i];
	}

	std::cout << COUNT[0] << " " << COUNT[1] << " " << COUNT[2];
	
	return 0;
}
#endif
