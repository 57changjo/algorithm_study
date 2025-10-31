#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int totalTime = 0;
	int N = 0;
	cin >> N;
	vector<int> P(N);

	for (int i = 0; i < N; i++) {
		cin >> P[i];
	}

	// 오름차순 정렬
	sort(P.begin(), P.end());

	for (int i = 0; i < N; i++) {
		totalTime += P[i] * (N - i);
	}

	cout << totalTime;

	return 0;
}

#endif
