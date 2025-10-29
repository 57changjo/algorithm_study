#if 01
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int N = A.size();
	int M = B.size();

	// DP[i][j] = A의 i-1번째까지, B의 j-1번째까지의 LCS 길이
	vector<vector<int>> DP(N+1, vector<int>(M+1, 0));

	// init - 위에서 이미 0으로 초기화됨
		
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (A[i - 1] == B[j - 1]) {
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else {
				DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	cout << DP[N][M] << "\n";

	// LCS 문자열까지 구하고 싶다면? - DP 계산 후 역추적
#if 0
	string lcs = "";
	int i = N, j = M;
	while (i > 0 && j > 0) {
		if (A[i - 1] == B[j - 1]) {
			// 맨 뒤에 원소 하나 추가
			lcs.push_back(A[i - 1]);
			i--; j--;
		}
		else if (DP[i - 1][j] > DP[i][j - 1]) {
			i--;
		}
		else {
			j--;
		}
	}
	reverse(lcs.begin(), lcs.end());
	cout << lcs;

#endif

	return 0;
}
#endif
