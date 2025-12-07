#if 0

#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> 

#define SIZE 100

using namespace std;

int N, M;
int answer = INT_MAX;


vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
vector<int> chicken_idx;

void calculate(void) {

	int total = 0;

	for (int i = 0; i < house.size(); i++) {

		int best = INT_MAX;

		for (int j = 0; j < chicken_idx.size(); j++) {
			int idx = chicken_idx[j];
			int dist = abs(house[i].first - chicken[idx].first) + abs(house[i].second - chicken[idx].second);

			best = min(best, dist);
		}

		total += best;
	}

	answer = min(answer, total);

}


// 조합 찾기
void choose_chicken(int idx, int cnt) {

	if (cnt == M) {
		calculate();
		return;
	}

	if (idx == chicken.size()) return;

	chicken_idx.push_back(idx);
	choose_chicken(idx + 1, cnt + 1);
	chicken_idx.pop_back();

	choose_chicken(idx + 1, cnt);
}


void input(void) {
	
	cin >> N >> M;

	int cur;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {

			cin >> cur;

			if (cur == 1) house.push_back({ i + 1, j + 1 });
			else if (cur == 2) chicken.push_back({ i + 1, j + 1 });
		}
	}
}

int main(void) {

	input();
	choose_chicken(0, 0);
	cout << answer;


	return 0;
}

#endif
