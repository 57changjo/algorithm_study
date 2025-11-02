#if 01
#include <iostream>
#include <vector>
#include <algorithm> // max
#include <cmath> // abs
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N = 0;
	cin >> N;
	vector<int> S(N);
	vector<int> B(N);
	for (int i = 0; i < N; i++) {
		cin >> S[i] >> B[i];
	}

    int answer = 1e9; // 큰 수로 초기화

    // 비트마스크 방식: 가능한 수 2*N - 1가지
    for (int mask = 1; mask < (1 << N); mask++) {
        int sour = 1; // 곱셈 초기값
        int bitter = 0; // 덧셈 초기값

        for (int j = 0; j < N; j++) {
            if (mask & (1 << j)) { // j번째 재료 사용
                sour *= S[j];
                bitter += B[j];
            }
        }

        answer = min(answer, abs(sour - bitter));
    }

    cout << answer << "\n";

	return 0;
}
#endif
