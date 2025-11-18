#if 01

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#define MAX_N (300+1)

using namespace std;

int stairs[MAX_N];
int c_stairs[MAX_N];
int N;

void Solve_Stairs(int n) {
	int cnt = 0;
	if (n == 1) {
		c_stairs[1] = stairs[1];
	}
	if (n == 2) {
		c_stairs[2] = stairs[1]+stairs[2];
	}
	else {
		c_stairs[1] = stairs[1];
		c_stairs[2] = stairs[1] + stairs[2];
		c_stairs[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);
		for (int i = 4; i <= N; i++) {
			for (int i = 4; i <= N; i++) {
				c_stairs[i] = max(stairs[i] + c_stairs[i - 2], c_stairs[i - 3] + stairs[i - 1] + stairs[i]);
				//두칸+한칸이 클 경우 다음 state에서 연속칸 선택해도 상관 없도록 설정
			}
		}
	}
}

int main(void) {
	(void)freopen("prob1.txt", "r", stdin);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> stairs[i];
	}
	
	Solve_Stairs(N);
	cout << c_stairs[N];

	return 0;
}

#endif
