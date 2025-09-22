#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a)(sizeof(a)/sizeof(a)[0])

#define MAX 50

int T, M, N, K;
int field[MAX][MAX];
int visited[MAX][MAX];
// hi
typedef struct {
    int r, c;
} node_t;

node_t Queue[MAX * MAX];
int front, rear;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };


void inputDataA(void) {
    (void)scanf("%d %d %d", &M, &N, &K);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            field[i][j] = 0;
            visited[i][j] = 0;
        }
    }
    for (int i = 0; i < K; i++) {
        int x, y;
        (void)scanf("%d %d", &x, &y);
        field[y][x] = 1;
    }
}


void BFS(int sr, int sc) {
    front = rear = 0;
    Queue[rear++] = (node_t){ sr, sc };
    visited[sr][sc] = 1;

    while (front != rear) {
        node_t curr = Queue[front++];
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
            if (field[nr][nc] == 0 || visited[nr][nc]) continue;

            visited[nr][nc] = 1;
            Queue[rear++] = (node_t){ nr, nc };
        }
    }
}

int main(void) {
    (void)scanf("%d", &T);
    while (T--) {
        inputDataA();
        int count = 0;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (field[i][j] == 1 && !visited[i][j]) {
                    BFS(i, j);
                    count++;
                }
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
