#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
- 2606에서 수정

입력: 첫째 줄에 정점의 개수 N과 간선의 개수 M이 주어진다. (1 ≤ N ≤ 1,000, 0 ≤ M ≤ N×(N-1)/2) 둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v가 주어진다. (1 ≤ u, v ≤ N, u ≠ v) 같은 간선은 한 번만 주어진다.
출력: 첫째 줄에 연결 요소의 개수를 출력한다.
*/
int N, M; // 정점 개수, 간선 개수
int arr[1001][1001]; // 연결 표시
int connected; // 연결 요소 개수
int visited[1001]; // 방문 정점 기록
// 편의상 1~1000의 인덱스 사용

void inputData() {
	(void)scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		(void)scanf("%d %d", &a, &b);
		arr[a][b] = 1; arr[b][a] = 1; // 연결 표시
	}
}

void func(int L) {
	// 같은 연결 안에서 방문
	for (int i = 1; i <= N; i++) {
		// 방문한 곳이나, 현재 것은 패스
		if (visited[i] == 1 || L == i) continue;
		// 그 이외에 연결되어 있으면 방문, 연결된 다음으로 넘어가기
		else if (arr[L][i] == 1) {
			visited[i] = 1;
			// printf("visit: %d\n", i);
			func(i);
		}
	}
}

int main() {
	//(void)freopen("b11724.txt", "r", stdin);
	inputData();

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) { // 방문하지 않은 곳부터 시작 - BFS 안에서 visited 확인하기 싫어서 이렇게 바꿈
			connected++;
			func(i); // i에서 DFS 시작 - 즉 1부터 시작 ㄱㄴ
		}
	}

	printf("%d\n", connected);

	return 0;
}
#endif
