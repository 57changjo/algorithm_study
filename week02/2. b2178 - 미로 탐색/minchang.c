#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NM (100 + 2)

int N, M;
int MAP[MAX_NM][MAX_NM];
int visited[MAX_NM][MAX_NM];

typedef struct _node {
    int r;
    int c;
}node;

node Queue[MAX_NM * MAX_NM];
int front, rear;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void inputData(void) {
    (void)scanf("%d %d", &N, &M);
    char temp[MAX_NM];

    for (int i = 1; i <= N; ++i) {
        (void)scanf("%s", temp + 1);
        for (int j = 1; j <= M; ++j) {
            MAP[i][j] = (temp[j] == '1') ? 1 : 0;
        }
    }
}

int bfs(int sr, int sc) {

    front = rear = 0;
    visited[sr][sc] = 1;
    Queue[rear++] = (node){ sr, sc };

    while (front != rear) {
        node curr = Queue[front++];

        for (int k = 0; k < 4; ++k) {
            int nr = curr.r + dr[k];
            int nc = curr.c + dc[k];

            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
            if (MAP[nr][nc] == 0) continue;
            if (visited[nr][nc] != 0) continue;

            visited[nr][nc] = visited[curr.r][curr.c] + 1;
			if (nr == N && nc == M) return visited[nr][nc];
            Queue[rear++] = (node){ nr, nc };
        }
    }
    return -1;
}

int main(void) {
    //(void)freopen("b2178.txt", "r", stdin);

    inputData();
    int rst = bfs(1, 1);
    printf("%d\n", rst);

    return 0;
}
#endif
