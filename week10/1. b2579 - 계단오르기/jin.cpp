#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include<cmath>
using namespace std;


int main(void) {
	int N = 0;
	cin >> N; // 계단의 갯수
	vector<int> score(N+1, 0); //각 계단 점수 
	vector<int> dp(N+1, 0); // 계단마다 최대 점수


	for (int i = 1;i <= N;i++) // 계단에 점수 넣기 
	{
		cin >> score[i];
	}

	// 실제 계단 값 구하기 전 3계단까지만은 최댓값이 확정되어 있으므로.(근데 만약 계단이 1개나 2개면?)

	dp[1] = score[1];
	if (N > 1) {
		dp[2] = score[1] + score[2];
	}
	if (N > 2) {
		dp[3] = max(score[1] + score[3], score[2] + score[3]);
	}

	//이제부터는 이전꺼를 기준으로 계속 최댓값 비교해서 넣어주기
	for (int i = 4; i <= N; i++) { 
		int case1 = dp[i - 3] + score[i - 1] + score[i]; // 2연속으로 올라왔을때
		int case2 = dp[i - 2] + score[i]; // 한칸 뛰고 올라왔을때
		dp[i] = max(case1, case2);
	}

	cout << dp[N]; //실제론 i가 0으로 설정하였으므로 0~N 까지 계산한 결과가 N+1 과 같으므로 N+1이아닌 N
	return 0;
}
