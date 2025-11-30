#if 01

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int T, n;


void inputdata() {
	cin >> n;
}

int solve() {
	int temp = 0;
	int ans = 0;
	for (int i = 0; i <= n/3 ; i++) {  // 3을 사용하는 경우(i=0에서는 2, 1만 사용하는 경우 뽑아줌)
		temp = n - (3 * i);
		ans += temp / 2 + 1;			// i=0에서는 1으로만 채우는 경우 1가지 추가, i>=1에서는 3+1의 조합 1가지 추가
	}

	return ans;
}

int main(void) {
	(void)freopen("prob2.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		inputdata();
		cout << solve() << '\n';
	}

	return 0;
}


#endif
