#if 01

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_N (1500000+2)

long T[MAX_N];
long P[MAX_N];
long dp[MAX_N];
long E_date[MAX_N];

long N;


void solve() {
	for (int i = 1; i <= N+1; i++) {
		dp[i] = max(dp[i], dp[i - 1]);			//상담하지 않는 날은 상담한 날의 누적값을 땡겨와서 dp테이블에 기록
		
		if(E_date[i] <= N+1){
			dp[E_date[i]] = max(dp[E_date[i]], dp[i]+P[i]);   
			//dp[E_date[i]] -> i일 상담의 종료날, i일 상담을 안했을 때의 value
			//dp[i]+P[i] ->i일의 상담을 했을 때의 value. dp[i]가 지난 누적값을 가지고 있으므로
			//누적 비교가 가능해짐 (E_date[i]로 다른 일자에서 발생하는 상담을 무시)
		}
	}
}

int main(void) {
	(void)freopen("prob2.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
		E_date[i] = T[i] + i;			//끝나는 날은 N+1일 일 수 있음
	}
	solve();
	cout << dp[N+1];

	return 0;
}

#endif
