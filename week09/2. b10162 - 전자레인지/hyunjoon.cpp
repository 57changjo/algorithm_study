#if 1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int A = 300;
int B = 60;
int C = 10;
int T;
int ans_A = 0, ans_B = 0, ans_C = 0;

int solve() {
	
	int left = 0;

	ans_A = T / A;
	T = T % A;
	ans_B = T / B;
	T = T % B;
	ans_C = T / C;
	left = T % C;

	return left;
}

int main() {
	//(void)freopen("prob2.txt", "r", stdin);
	cin >> T;
	int ans = solve();
	if (ans) {
		cout<< -1;
	}
	else {
		cout << ans_A << ' ' << ans_B << ' ' << ans_C;
	}
	return 0;
}

#endif
