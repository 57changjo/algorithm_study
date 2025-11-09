#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cmath>
using namespace std;


int main(void) {
	int N = 0;
	cin >> N; // 퇴사일 하루 전날
	vector<int> T(N,0); //상담 시간
	vector<int> P(N,0); //상담 비용
	vector<int> dp(N+50, 0); // i날에 최대로 받을 수 있는 돈


	for (int i = 0;i < N;i++) // 각각 시간과 비용 넣기 
	{
		cin >> T[i] >> P[i];
	}

	for (int i = 0; i < N; i++) {
		dp[i + T[i]] = max(dp[i] + P[i],dp[i+T[i]]); //i 날 일을 할 때
		dp[i + 1] = max(dp[i], dp[i + 1]); //i날 일을 안할 때
	}

	cout << dp[N]; //실제론 i가 0으로 설정하였으므로 0~N 까지 계산한 결과가 N+1 과 같으므로 N+1이아닌 N
	return 0;
}
