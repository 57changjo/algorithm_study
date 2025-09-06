#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
- 연결되어 있음, but 4방향 체크 아니기 때문에 DFS로 충분함
- 연결되어 있는 걸 어떻게 저장할까? arr[i][j]: i, j 연결. 단, 방향성 양뱡 (즉, arr[i][j], arr[j][i] 같은 값으로 저장하기, 또한 arr[x][x]는 continue 하는 방식으로

- 입력: 첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하인 양의 정수이고 각 컴퓨터에는 1번 부터 차례대로 번호가 매겨진다. 둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다. 이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.
- 출력: 1번 컴퓨터가 웜 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 웜 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.
*/

int N, M; // 컴퓨터 개수, 연결 개수
int arr[101][101]; // 연결 표시
int virus; // 바이러스 컴 개수
int visited[101]; // 방문 컴 기록
// 편의상 1~100의 인덱스 사용

void inputData() {
	(void)scanf("%d", &N);
	(void)scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		(void)scanf("%d %d", &a, &b);
		arr[a][b] = 1; arr[b][a] = 1; // 연결 표시
	}
}

void func(int L) {

	for (int i = 1; i <= N; i++) {
		// 방문한 곳이나, 현재 컴은 패스
		if (visited[i] == 1 || L == i) continue;
		// 그 이외에 연결되어 있으면 방문, 바이러스 + 연결된 다음으로 넘어가기
		else if (arr[L][i] == 1) {
			visited[i] = 1;
			virus++;
			//printf("visit: %d\n", i);
			func(i);
		}
	}
	return;
}

int main() {
	//(void)freopen("b2606.txt", "r", stdin);
	inputData();

	visited[1] = 1; // 첫 시작 방문 표시
	func(1);

	printf("%d\n", virus);

	return 0;
}
#endif