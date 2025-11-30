#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

#define MAX_H 500

enum fill {
	open = 1,
	close = 0
};

int map[MAX_H][MAX_H];
vector<int> pillar;

int H, W;

void inputdata() {
	cin >> H >> W;

	for (int i = 0; i < W; i++) {
		int num = 0;
		cin >> num;
		pillar.push_back(num);
	}
	for (int i = 0; i < W; i++) {
		for (int j = 0; j < pillar[i]; j++) {
			map[j][i] = 1;
		}
	}
}

void printdata() {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}

int rain() {
	int max_pillar = *max_element(pillar.begin(), pillar.end());
	int cnt = 0;
	for (int i = max_pillar-1; i >= 0; i--) {
		int start = 0;
		int flag = close;
		for (int j = 0; j < W; j++) {
			if (map[i][j] == 1) {
				if (flag == open) {
					cnt += j - start - 1;
					start = j;
				}
			else{
				flag = open;
				start = j;
				}
			}
		}
	}
	return cnt;
}


int main(void) {
	(void)freopen("prob3.txt", "r", stdin);
	inputdata();
	cout << rain();

	return 0;
}
#endif
