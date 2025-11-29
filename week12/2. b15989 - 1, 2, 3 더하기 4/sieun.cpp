#if 01
/*
1만으로 더하는 경우, 2가 포함되는 경우, 3도 포함되는 경우를 모두 포함하기
왜냐면 i번째를 생각하면 i-1에서 1 더하는 것, i-2에서 2 더하는 것, i-3에서 3 더하는 것으로 나눌 수 있는데, 
중복의 경우를 피하기 위해서 위와 같이 케이스를 나눌 수 있다
그런데 while에서 각 n마다 sum_solve를 호출해서 답을 구하는 방식을 사용하면 런타임 에러가 발생한다. 
이를 10000까지의 모든 DP를 계산해놓고, while에서 DP를 가져와 쓰는 방식으로 하면 수정하면 해결된다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1-based index 사용함 (가독성)
vector<vector<int>> DP(10001, vector<int>(4, 0));

void sum_solve() {
	DP[1][1] = 1;
	DP[2][1] = 1; DP[2][2] = 1;
	DP[3][1] = 1; DP[3][2] = 1; DP[3][3] = 1;

	for (int i = 4; i <= 10000; i++) {
		DP[i][1] = DP[i - 1][1];
		DP[i][2] = DP[i - 2][1] + DP[i - 2][2];
		DP[i][3] = DP[i - 3][1] + DP[i - 3][2] + DP[i - 3][3];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T = 0;
	int n = 0;
	cin >> T;

	sum_solve();

	while (T-- > 0) {
		cin >> n;
		cout << DP[n][1] + DP[n][2] + DP[n][3] << "\n";
	}

	return 0;
}
#endif
