#if 01

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
int C;
vector<int> x;
vector<int> d;



void inputdata(void) {
	int num = 0;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> num;
		x.push_back(num);
	}
	for (int i = 1; i < N; i++) {
		d.push_back(x[i] - x[i - 1]);
	}
	sort(x.begin(), x.end());
}

//int binsearch() {
//	sort(d.begin(), d.end());
//}


int solve(void) {
	/*int ans = 0;*/
	int start = 0, end = x.back();
	int mid = (start + end) / 2;
	int dist = 0;
	if (C == 2) {
		return x.back() - x.front();
	}
	while (start<=end) {
		int temp_c = C - 1;
		int mid = (start + end) / 2;
		//cout << "dist: " << dist << "\n";
		for (int i = 0; i < N - 1; i++) {
			//cout << i << "\n";
			for (int j = i + 1; j < N; j++) {
				int sub = x[j] - x[i];
				//cout << x[j] << ' ' << x[i] << "\n";
				if (sub >= mid) {			//sub >=mid == 공유기를 놓을 수 있음
					temp_c--;		//공유기 놓기
					i = j - 1;				//놓은 자리에 커서 위치
					//cout << "i : " << i << '\n';
					break;
				}
			}
			if (!temp_c) break;
		}
		//낮으면 증가
		//크면 다시 중앙값 찾기
		if (!temp_c) {				//temp_c 가 0이라는 것은 -> 공유기를 다 놓음 -> 더 큰 dist를 넣어봐야 함
			dist = mid;
			start = mid + 1;
		}
		else							//	temp 
			end = mid - 1;
	}
	return dist;
}


int main() {
	(void)freopen("prob2.txt", "r", stdin);
	inputdata();
	cout << solve();

	return 0;
}

#endif
