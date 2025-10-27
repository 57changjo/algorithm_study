#if 1
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <string>



#define MAX_M  (1000+1)
#define MAX_N  (1000+1)

using namespace std;

int map[MAX_N][MAX_M];
int dp[MAX_N][MAX_M];

int N, M;

//내가 있는 곳 뒤의 3방향(왼,위,왼위)에 누적된 값을 보고 어디에서 왔어야 최대값을 낼 수 있는지 현재 있는 곳에 갱신(정확히는 DPmap에)
void Candy() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = map[i][j] + max({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] });  //algorithm 헤더의 max 함수 사용
		}
	}
}

void inputdata() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> map[i][j];
		}
	}
}
int main(void) {
	(void)freopen("prob2.txt", "r", stdin);
	cin >> N >> M;
	inputdata();
	Candy();
	cout << dp[N][M];
	return 0;
}


#endif
