#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	int N = 0;
    cin >> N;
	vector<int> T(N + 1), P(N + 1);
    for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
    }

    // 돈을 언제 받을 수 있는지에 대한 정의가 필요함
    // i일까지 상담받으면 i+1일에 돈을 받음
    vector<int> DP(N + 2, 0); // N+1일까지 고려

    for (int i = 1; i <= N; i++) {
        DP[i + 1] = max(DP[i + 1], DP[i]); // 오늘 상담 안 함
        if (i + T[i] <= N + 1)              // 오늘 상담 가능
            DP[i + T[i]] = max(DP[i + T[i]], DP[i] + P[i]);
    }

    cout << DP[N + 1];

    return 0;
}
#endif
