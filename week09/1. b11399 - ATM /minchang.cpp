#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <cstdio>
	
using namespace std;

int N;
int timeCounts[1001];

void inputData(void) {
	cin >> N;
	int p;
	for (int i = 0; i < N; ++i) {
		cin >> p;
		timeCounts[p]++;
	}
}

int solve(void) {
	int totalSum = 0;
	int currentWait = 0;

	for (int i = 1; i <= 1000; ++i) {
		for (int j = 0; j < timeCounts[i]; ++j) {
			currentWait += i;
			totalSum += currentWait;
		}
	}

	return totalSum;
}

int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	//(void)freopen("b11399.txt", "r", stdin);
	inputData();
	cout << solve();

	return 0;
}


