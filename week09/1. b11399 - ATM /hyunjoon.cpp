#if 1

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
#define MAX_N 1000


int Atm[MAX_N];
int K;



int solve() {
	int sum = 0;
	sort(Atm, Atm + K);
	for (int i = 0; i < K; i++) {
		sum += (K - i) * Atm[i];
	}
	return sum;
}


int main() {
	(void)freopen("prob1.txt", "r", stdin);

	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> Atm[i];
	}
	cout << solve();

	return 0;
}

#endif
