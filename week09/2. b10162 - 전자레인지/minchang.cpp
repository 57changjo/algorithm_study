#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
	
using namespace std;

int N;
int A = 300, B = 60, C = 10;
int aCnt, bCnt, cCnt;

void inputData(void) {
	cin >> N;
}

void solve(void) {
	if (N % 10 != 0) {
		cout << -1;
		return;
	}
	aCnt = N / A;
	N %= A;
	bCnt = N / B;
	N %= B;
	cCnt = N / C;
	N %= C;
	cout << aCnt << " " << bCnt << " " << cCnt;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//(void)freopen("b10162.txt", "r", stdin);
	inputData();
	solve();

	return 0;
}


