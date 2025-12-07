#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct _belt_t {
	int dur, robot;
}typedef belt_t;

int N , K;
vector<belt_t> belt;

void inputdata() {
	cin >> N >> K;
	for (int i = 0; i < 2*N; i++) {
		int num;
		cin >> num;
		belt_t temp = { num, 0 };
		belt.push_back(temp);
	}
}

void printarr() {
	for (int i = 0; i < N; i++) {
		cout << belt[i].dur << " ";
	}
	cout << "\n";
	for (int i = 2 * N - 1; i >= N; i--) {
		cout << belt[i].dur << " ";
	}
	cout << "\n";

	for (int i = 0; i < N; i++) {
		cout << belt[i].robot << " ";
	}
	cout << "\n";
	for (int i = 2 * N - 1; i >= N; i--) {
		cout << belt[i].robot << " ";
	}

	cout << "\n";
	cout << "\n";
}

void swap(belt_t* a, belt_t* b) {
	belt_t tmp = *a;
	*a = *b;
	*b = tmp;
}

void unload_robot() {
	belt[N-1].robot = 0;
}

void roll() {
	belt_t tmp = belt.front();
	for (int i = 1; i < 2 * N; i++) {
		swap(&tmp, &belt[i]);
	}
	swap(&belt[0], &tmp);
	unload_robot();
	/*cout <<  "roll \n";
	printarr();*/
}



void mov_robot() {
	for (int i = 2*N-1; i >0; i--) {
		if (belt[i].dur > 0 && belt[i-1].robot && !belt[i].robot) {
			belt[i-1].robot = 0;
			belt[i].robot = 1;
			--belt[i].dur;
		}
		unload_robot();
	}
	/*cout << "mov \n";
	printarr();*/
}

void load_robot() {
	if (belt.front().dur > 0) {
		--belt.front().dur;
		belt.front().robot = 1;
	}
	/*cout << "load \n";*/
}

int isend(){
	int cnt = 0;
	for (int i = 0; i < 2 * N; i++) {
		if (belt[i].dur > 0) {
			continue;
		}
		++cnt;
		if (cnt >= K) {
			return 0;
		}
	}
	return 1;
}

int solve() {
	int phase = 0;
	while (1) {
		++phase;
		/*cout << phase << "\n";*/
		roll();
		mov_robot();
		load_robot();
		//printarr();
		if (!isend()) return phase;
	}
}

int main(void) {
	(void)freopen("prob3.txt", "r", stdin);
	inputdata();
	cout << solve();
	return 0;
}
#endif
