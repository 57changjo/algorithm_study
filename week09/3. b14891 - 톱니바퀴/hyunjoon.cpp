#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int Clock[4 + 1][8 + 1];
int K;
int Con[4];

void spinclock(int dir, int* bearing) {
	int start = 0, end = 0;
	if (dir == 1) {								//시계
		for (int i = 8; i >= 1; i--) {
			if (i == 1) {
				bearing[i] = end;
			}
			else if (i == 8) {
				end = bearing[i];
				bearing[i] = bearing[i - 1];
			}
			else {
				bearing[i] = bearing[i - 1];
			}
		}
	}
	if (dir == -1) {							//반시계
		for (int i = 1; i <= 8; i++) {
			if (i == 1) {
				start = bearing[i];
				bearing[i] = bearing[i + 1];
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

void printclock(int* bearing) {				//디버깅용
	for (int i = 1; i <= 8; i++) {
		cout << bearing[i];
	}
	cout << '\n';
}


void scan_connect() {					//톱니바퀴가 서로 돌릴 수 있는지(연결되어있는지) 확인
	for (int i = 1; i <= 3; ++i) {
		if (Clock[i][3] == Clock[i + 1][7]) {
			Con[i] = 0;
		}
		else {
			Con[i] = 1;
		}
	}
	//cout << Con[1] << Con[2] << Con[3]<< '\n';
}

void solve(int num, int dir) {
	int dir_org = dir;
	int pre_con = 1;
	int R_start = num + 1, L_start = num - 1;
	scan_connect();
	spinclock(dir, Clock[num]);

	for (int i = R_start; i <= 4; ++i) {
		dir = (-1) * dir;
		if (!Con[i - 1] || !pre_con) {
			break;
		}
		//cout <<"stage debug_r : "<<i<<'\n';
		spinclock(dir, Clock[i]);
		pre_con = Con[i - 1];
	}

	dir = dir_org;
	pre_con = 1;							//초기값 설정

	for (int i = L_start; i >= 1; --i) {
		dir = (-1) * dir;
		if (!Con[i] || !pre_con) {
			break;
		}
		//cout << "stage debug_L : " << i << '\n';
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
	//(void)freopen("prob3.txt", "r", stdin);
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 8; j++) {
			(void)scanf("%1d", Clock[i] + j);
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
