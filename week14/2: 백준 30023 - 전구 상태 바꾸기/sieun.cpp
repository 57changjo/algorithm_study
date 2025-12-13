#if 01
/*
R -> G -> B -> R
연속한 세 전구 상태 바꿈 -> 앞에서부터 순차적으로 바꿔야겠다.
모든 전구 색깔이 R, G, B인 경우를 각각 구해서 그 중에 최솟값을 출력
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, cnt;
vector<int> origin;
vector<int> rgb;

void inputData() {
	string s;
	cin >> N;
	cin >> s;

	rgb.resize(N, 0);
	for (int i = 0; i < N; i++) {
		if (s[i] == 'R')
			origin.push_back(0);
		else if (s[i] == 'G')
			origin.push_back(1);
		else if (s[i] == 'B')
			origin.push_back(2);
	}
}


void change(int i, int plus) {
	int k = 0;
	while (k < 3) {
		rgb[i + k] += plus;
		rgb[i + k] %= 3;
		k++;
	}	
	cnt += plus;
}

int solve(int goal) {
	rgb = origin;
	cnt = 0;

	for (int i = 0; i <= N-3; i++) {
		// goal - rgb[i] = 2, 1, 0, -1, 2
		switch (goal - rgb[i]) {
		case 2: // +2
			change(i, 2);
			break;
		case 1: // +1
			change(i, 1);
			break;
		case 0:
			break;
		case -1: // +2
			change(i, 2);
			break;
		case -2: // +1
			change(i, 1);
			break;
		}
	}

	// 마지막 두 칸도 맞아야 함 -> 안 맞으면 불가능한 경우 10^9로
	if (rgb[N - 1] != goal || rgb[N - 2] != goal)
		return 1e9;
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inputData();
	int ans0 = solve(0);
	int ans1 = solve(1);
	int ans2 = solve(2);
	int real_ans = min({ ans0, ans1, ans2 });
	// 만약 모든 전구가 같은 색으로 빛나게 할 수 없다면 -1을 출력한다.
	if (real_ans == 1e9) 
		real_ans = -1;
	cout << real_ans;

	return 0;
}

#endif
