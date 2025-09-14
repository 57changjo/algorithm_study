#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100001
int N, K;
int front, rear;
int visit[MAX_N];
int cnt[MAX_N]; // N부터 해당 장소까지 갈 수 있는 방법의 수
int Queue[MAX_N];

void inputData() {
	scanf("%d %d", &N, &K);
}

void BFS_sbgj() {
	front = rear = 0;
	int curr = 0;
	Queue[rear++] = N;
	visit[N] = 1;
	cnt[N] = 1;

	while (front != rear) {
		curr = Queue[front++];
		//printf("curr : %d, vis : %d, cnt: %d\n", curr, visit[curr], cnt[curr]);

		int dd[3] = { -1, 1, curr };
		for (int i = 0; i < 3; i++) {
			int next = curr + dd[i];
			if (next < 0 || next > MAX_N) continue;
			// visit 갱신
			if (!visit[next]) {
				visit[next] = visit[curr] + 1;
				Queue[rear++] = next;
			}
			// cnt 갱신
			if (!cnt[next]) cnt[next] = cnt[curr];
			else if (visit[curr] + 1 == visit[next]) cnt[next] += cnt[curr];
			// else if (visit[curr] + 1 == visit[next]) cnt[next] = cnt[curr] + 1; // 5 100000 -> 틀림
		}
	}
}

int main() {
	inputData();
	BFS_sbgj();
	printf("%d %d", visit[K] - 1, cnt[K]);

	return 0;
}
#endif
