#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_K 1299709

int T, k;

void inputdata() {
	cin >> k;
}

int isprime(int k) {
	for (int i = 2; i*i <= k; i++) {
		if (k % i == 0) {
			return 0;
		}
		else continue;
	}
	return 1;
}

int solve() {
	int cnt = 0;
	for (int i = k; i > 0; i--) {  //아래 세기
		if (isprime(i)) {
			break;
		}
		else cnt++;
	}
	for (int i = k; i <= MAX_K; i++) {  //위쪽 세기
		if (isprime(i)) {
			break;
		}
		else cnt++;
	}
	return cnt;
}


// 자신이 아닌 뭔가로 나눌 때 나눠지면 합성수, 자기 자신 아니면 1로만 나눠지면 아니면 소수

int main() {
	(void)freopen("prob1.txt", "r", stdin);
	cin >> T;
	for (int i = 0; i < T; i++) {
		inputdata();
		cout << solve() << "\n";
	}

	return 0;
}

#endif 
