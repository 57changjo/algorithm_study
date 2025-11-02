#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

#define MAX_N 100
using namespace std; 

int Clock[4+1][8+1];
int K;
int Con[4];

void spinclock(int dir, int* bearing) {
	int start= 0, end = 0;
	if (dir == 1) {								//시계
		for (int i = 8; i > 0; i--) {
			if (i == 1) {
				bearing[i] = end;
			}
			if (i == 8) {
				int end = bearing[i];
			}
			else {
				bearing[i] = bearing[i - 1];
			}
		}
	}
	if (dir == -1) {							//반시계
		for (int i = 1; i <= 8; i++) {
			if (i == 1) {
				int start = bearing[i];
			}
			if (i == 8) {
				bearing[i] = start;
			}
			else {
				bearing[i] = bearing[i + 1];
			}
		}
	}
}

int spinclock2(int dir, int* bearing) {
	int start = 0, end = 0;
	if (dir == 1) {
		return bearing[8];
	}
	if (dir == -1) {							//반시계
		return bearing[2];
	}
	else return bearing[1];
}


void scan_connect(int num) {
	for (int i = 1; i <= 3; ++i) {
		if (Clock[i][3] == Clock[i + 1][7]) {
			Con[i] = 0;
		}
		else {
			Con[i] = 1;
		}
	}
}

void solve(int num, int dir) {
	int dir_org = dir;
	int pre_con = 1;
	int R_start = num + 1, L_start = num - 1;
	int cnt = 0;

	spinclock(dir, Clock[num]);

	for (int i = R_start; i <= 4; ++i) {
		dir = (-1) * dir;
		if (!Con[i - 1] || !pre_con) {
			break;
		}
		spinclock(dir, Clock[i]);
		pre_con = Con[i-1];
	}
	
	dir = dir_org;
	pre_con = 1;							//초기값 설정

	for (int i = L_start; i >= 1; --i) {
		dir = (-1) * dir;
		if (!Con[i] || !pre_con) {
			break;
		}
		spinclock(dir, Clock[i]);
		pre_con = Con[i];
	}
}

int value() {
	int cnt = 0;
	for (int i = 1; i <= 4; i++) {
		if (Clock[i][1]) {
			cnt += 0x1 << (i - 1);
		}
	}
	return cnt;
}

int main(void) {
	int num = 0, dir = 0;
	int cnt = 0;
	(void)freopen("prob3.txt", "r", stdin);
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			(void)scanf("%1d", Clock[i]+j);
		}
	}
	cin >> K;

	for (int i = 0; i < K; i++) {
		cin >> num >> dir;
		solve(num, dir);
	}

	cout << value();

	
	return 0;
}

