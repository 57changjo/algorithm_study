#if 0

#include <iostream>
#include <algorithm>
#include <vector>

#define SIZE 500

/*
* 1 < 5
* 3 < 4
* 5 < 4
* 4 < 2
* 4 < 6
* 5 < 2
* 
* 학생들은 본인과 다른 학생 한명이랑 키를 비교 한다.
* 나보다 큰 학생들, 나보다 작은 학생들의 수를 모르니깐 본인의 키가 몇 순위인지 모르는거임
*/

void dfs(int now, std::vector<int> students[], int visited[], int& cnt) {

	visited[now] = 1;

	for (int i = 0; i < students[now].size(); i++) {
		int next = students[now][i];

		if (!visited[next]) {
			cnt++;
			dfs(next, students, visited, cnt);
		}
	}
}

int main(void) {

	int N, M;
	int a, b;

	std::vector<int> bigger[501];
	std::vector<int> smaller[501];

	std::cin >> N >> M;

	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;

		bigger[a].push_back(b);
		smaller[b].push_back(a);
	}

	int visited[501];
	int result = 0;

	for (int i = 1; i <= N; i++) {

		for (int j = 1; j <= N; j++) {
			visited[j] = 0;
		}

		int biggerCount = 0;
		dfs(i, bigger, visited, biggerCount);

		for (int k = 1; k <= N; k++) {
			visited[k] = 0;
		}

		int smallerCount = 0;
		dfs(i, smaller, visited, smallerCount);

		if (biggerCount + smallerCount == N - 1) {
			result++;
		}
	}

	std::cout << result;

	return 0;
}

#endif
