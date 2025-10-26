#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int k1, k2;
int b[3];
int dp[500+1][500+1];

int solve() {
	for (int i = k1; i >= 0; --i) {
		for (int j = k2; j >= 0; --j) {
      //result 만듦
			int whosturn = 0;
      //for문 돌면서 b[K]만큼 구슬을 뽑을 수 있을 때, 지금이 누구의 턴인지(전 턴이 B이면 다음은 A) 계속 판정 내가 이길 수 있는 조건 -> 턴을 진행시킬 수 있는가? -> 턴을 진행시킬 수 있으면 기록
			for (int k = 0; k < 3; ++k) {
				if (i <= k1-b[k] && !dp[i + b[k]][j]) {
					whosturn = 1;
				}
				if (j <= k2-b[k] && !dp[i][j + b[k]]) {
					whosturn = 1;
				}
			}
			dp[i][j] = result;  // 전 턴이 A면 B
		}
	}
	return dp[0][0];
}


int main() {
	//(void)freopen("prob3.txt", "r", stdin);
	int cnt = 5;
	cin >> b[0] >> b[1] >> b[2];
	while (cnt-- > 0) {
		cin >> k1 >> k2;
		solve() ? cout << 'A' : cout << 'B';
		cout << '\n';
	}

	return 0;

	
}
