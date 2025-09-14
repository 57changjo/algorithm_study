#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_NM (50 + 2)

int T;
int M, N, K;
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

void input_case(void) {
    (void)scanf("%d %d %d", &M, &N, &K);
    memset(MAP, 0, sizeof(MAP));
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < K; ++i) {
        int x, y;
        (void)scanf("%d %d", &x, &y);
        MAP[y][x] = 1;
    }
}

void bfs(int sr, int sc) {
	front = rear = 0;
    node curr = { 0 };
    visited[sr][sc] = 1;
	Queue[rear++] = (node){ sr, sc };
    while (front != rear) {
		curr = Queue[front++];
        for (int k = 0; k < 4; ++k) {
            int nr = curr.r + dr[k];
            int nc = curr.c + dc[k];
            if (visited[nr][nc]) continue;
            if (MAP[nr][nc] == 0) continue;
            visited[nr][nc] = 1;
			Queue[rear++] = (node){ nr, nc };
        }
    }
}

int main(void) {
    //(void)freopen("b1012.txt", "r", stdin);

    (void)scanf("%d", &T);
    while (T--) {
        input_case();

        int cnt = 0;
        for (int r = 0; r < N; ++r) {
            for (int c = 0; c < M; ++c) {
                if (MAP[r][c] == 1 && !visited[r][c]) {
                    bfs(r, c);
                    ++cnt;
                }
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
#endif
