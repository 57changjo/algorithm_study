#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;
typedef long long ll;
int N;
ll S[10]; // Sour
ll B[10]; // Bitter
ll min_diff = LLONG_MAX;

void inputData(void) {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> B[i];
	}
}

void solve(int idx, ll current_S, ll current_B) {

	if (idx == N) {
		if (current_S == 1 && current_B == 0) {
			return; // no choice
		}

		ll current_diff = abs(current_S - current_B);
		min_diff = min(min_diff, current_diff);

		return; // 재귀 종료
	}

	// 안 쓰는 경우
	solve(idx + 1, current_S, current_B);

	// 쓰는 경우
	solve(idx + 1, current_S * S[idx], current_B + B[idx]);
}


int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	(void)freopen("b10162.txt", "r", stdin);
	inputData();

	solve(0, 1, 0);

	cout << min_diff;

	return 0;
}
