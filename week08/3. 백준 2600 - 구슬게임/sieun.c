#if 01
// A가 먼저 선택하기 때문에 A가 이기는 방법으로 갈 수 있으면 A가 이기고, 그렇지 않으면 B가 이김
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int b1, b2, b3;
	cin >> b1 >> b2 >> b3;

	int k1, k2;
	int cnt = 5;
	while (cnt-- > 0) {
		cin >> k1 >> k2;
		vector<vector<bool>> DP(k1 + 1, vector<bool>(k2 + 1, false));
		// 구슬이 i개, j개일 때 A가 이길 수 있으면 true

		for (int i = 0; i <= k1; ++i) {
			for (int j = 0; j <= k2; ++j) {
				// init (0,0): false, 이미 초기화되어 있음
				if (i == 0 && j == 0) continue;

				bool canWin = false;
				int b[3] = { b1, b2, b3 };

				for (int x : b) {
					// 한 통에서 x만큼 빼서 상대가 지면 -> A 이김
					if (i >= x && !DP[i - x][j]) canWin = true;
					if (j >= x && !DP[i][j - x]) canWin = true;
				}

				DP[i][j] = canWin;
			}
		}

		cout << (DP[k1][k2] ? "A" : "B") << "\n";
	}
	return 0;
}


#endif
