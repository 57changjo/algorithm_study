#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_D (10000+1)

class shortcut_c {
public:
	int start = 0;
	int distance = 0;
};

int D;
int N;


int dp[MAX_D];
vector<vector<shortcut_c>> shortcut(MAX_D);

void inputdata(void) {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		int start, end, distance;
		cin >> start >> end >> distance;
		if (end<=D && (end - start) > distance) {
			shortcut[end].push_back({ start, distance});
		}
	}
}

void printdata(void) {
	
}

int solve(){
	int temp = 0;
	for (int i = 1; i <= D; i++) { dp[i] = i; }
	for (int i = 1; i <= D; i++) {
		//dp는 0km부터 ikm까지 이동했을 때에 걸린 최소 거리
		dp[i] = dp[i - 1] + 1;
		for (int j = 0; j < shortcut[i].size(); j++) {
			dp[i] = min(dp[i], dp[shortcut[i][j].start] + shortcut[i][j].distance); //도착지 기준 나는 지름길 해서 왔거나, 그냥 정직하게 1km 운전했거나
		}// 의문 : 도착지가 같은 경우는 어떻게 하지? index 중복 아닌가?
	}
	return dp[D];
}

int main(void) {
	(void)freopen("prob1.txt", "r", stdin);
	inputdata();
	
	int ans = solve();
	cout << ans;
	return 0;
}

#endif
