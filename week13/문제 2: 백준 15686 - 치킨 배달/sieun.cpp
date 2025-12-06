#if 01
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>  // abs
using namespace std;

int N, M;
int answer = 2e9; // 20억
vector<pair<int, int>> house, chicken, temp; // temp는 M개의 치킨집 임시 저장

void inputData() {
	int temp = -1;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp;
			if (temp == 2)
				chicken.push_back({ i, j });
			else if (temp == 1)
				house.push_back({ i, j });
		}
	}
}

int distance() {
	int sum = 0;

	for (int i = 0; i < house.size(); i++) {
		int mini = 2e9;

		for (int j = 0; j < temp.size(); j++) {
			int x = abs(temp[j].first - house[i].first);
			int y = abs(temp[j].second - house[i].second);
			mini = min(mini, x + y);
		}

		sum += mini;
	}

	return sum;
}

void DFS(int index) {
	if (temp.size() == M) {
		answer = min(answer, distance());
		return;
	}

	for (int i = index; i < chicken.size(); i++) {
		temp.push_back(chicken[i]);
		DFS(i + 1);
		temp.pop_back();
	}
}

int main() {
	ios::sync_with_stdio;
	cin.tie(nullptr);

	inputData();
	DFS(0);

	cout << answer;

	return 0;
}

#endif
