#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE (1000 + 1)

int N, M;
int U, V;
int visited[SIZE] = { 0 };
int graph[SIZE][SIZE] = { 0 };
int connected = 0;

void DFS(int n) {

	// 방문했다고 표시
	visited[n] = 1;

	for (int i = 1; i <= N; i++) {

		if (graph[n][i] == 1 && visited[i] == 0) {

			DFS(i);
		}
	}
}

int main(void) {

	// 연결 요소의 개수 구하기

	// 첫째 줄에서 정점(N) 간선(M) 불러오기
	// 둘째 줄부터 M개 만큼 끝점 u v 불러오기

	(void)scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++) {
		
		// 끝점 받아오기
		(void)scanf("%d %d", &U, &V);

		// 방향 없는 그래프, 서로 연결되었다고 표시
		graph[U][V] = 1;
		graph[V][U] = 1;
	}

	// 각 정점 체크
	for (int j = 1; j <= N; j++) {

		if (visited[j] == 0) {

			DFS(j);
			connected++;
		}
	}

	printf("%d\n", connected);

	return 0;
}
