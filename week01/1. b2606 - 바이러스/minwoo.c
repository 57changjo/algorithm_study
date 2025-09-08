#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 100 + 1

int visited[SIZE] = { 0 };
int graph[SIZE][SIZE] = { 0 };
int computers = 0;
int connected = 0;
int infected = 0;

void DFS(int n) {

	visited[n] = 1;

	for (int i = 1; i <= computers; i++) {

		// 연결되어 있고, 아직 방문 안 했으면 감염 count 추가, 재귀 호출
		if (graph[n][i] == 1 && visited[i] == 0) {

			infected++;
			DFS(i);
		}
	}
}

int main(void) {

	// 첫 입력은 네트워크 안에 있는 총 컴퓨터의 수
	// 두번째 입력은 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수

	// 풀이 접근 방법
	// 일단 첫 번째 입력을 불러온다 (네트워크 안에 있는 총 컴퓨터의 수 computers)
	// 두번째 입력을 가져와서 그 크기 만큼 for loop 돌리면서 graph 에 불러온 컴퓨터들의 쌍들을 넣어서 연결되었다고 표시

	int x, y;

	(void)scanf("%d %d", &computers, &connected);
	
	// x y 는 연결된 컴퓨터들의 번호, 이걸 graph에 바로 넣어서 값을 1로 초기화 함, 이 둘은 서로 연결되어 있다는 뜻
	for (int i = 0; i < connected; i++) {

		(void)scanf("%d %d", &x, &y);
		graph[x][y] = 1;
		graph[y][x] = 1;
	}

	DFS(1);

	printf("%d\n", infected);
	
	return 0;
}
