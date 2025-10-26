#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(int N, int M, const vector<vector<int>>& grid) {
	// DP[i][j] = (1,1)에서 (i,j)까지의 최대 사탕 개수
	vector<vector<int>> DP(N+1, vector<int>(M+1, 0));
	// init
	DP[0][0] = 0;
	DP[0][1] = 0;
	DP[1][0] = 0;

	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			// init
			if (i == 1 && j == 1) DP[1][1] = grid[1][1];
			else {
				DP[i][j] = max({ DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1] }) + grid[i][j];
			}
		}
	}
	return DP[N][M];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> grid(N + 1, vector<int>(M + 1, 0));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			cin >> grid[i][j];
		}
	}

	cout << solve(N, M, grid);

	return 0;
}

#endif
