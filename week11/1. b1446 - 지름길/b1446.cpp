#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MAX 10000+1

using namespace std;
int N, D, first, ended , km; //N = 지름길, D =고속도로 거리 ,first 시작 end 끝 km = 거리
int dp[MAX];//실제 경로가 감에따라 누적할 수
vector<pair<int, int> > Vec[MAX];

/* 실제 경로마다 숫자를 넣어서 이를 기준으로 더해서 최단 거리 도출하자*/
void init() {
	for (int i = 0; i < MAX; i++) {
		dp[i] = i;
	}
}

void input() {
	cin >> N >> D;
	for (int i = 0; i < N; i++) {
		cin >> first >> ended >> km;
		Vec[first].push_back(make_pair(ended, km)); // 지름길 시작 위치일때 도착지와 거리 값 입력
	}
}

void solve() {
	for (int i = 0; i <= D; i++) { // 도착지 까지 모든 출발거리에 대해 점검
		for (int j = 0; j < N; j++) { // 최대 N개 까지 겹칠 수 있잖아
			int To = Vec[i][j].first; // 도착지 정보 저장
			int distance = Vec[i][j].second; // 도착지 까지의 거리(지름길 탈때) 값 저장
			for (int k = To; k <= D; k++) {
				dp[k] = min(dp[k], dp[i] + distance + (k - To)); // 여태까지의 최소거리랑 현 지름길 탔을때랑 비교
			}
		}
	}
}

void print() {
	cout << dp[D] << "\n";
}

int main() {
	init();
	input();
	solve();
	print();

	return 0;

}
