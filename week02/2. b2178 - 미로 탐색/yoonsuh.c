#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a)(sizeof(a)/sizeof(a)[0])

#define MAX 100

int N, M;
int maze[MAX][MAX];
int dist[MAX][MAX];
int visited[MAX][MAX];

typedef struct {
    int r, c;
} node_t;

node_t Queue[MAX * MAX];
int front, rear;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };


void inputDataA(void) {
    (void)scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        char s[101];
        (void)scanf("%s", s);
        for (int j = 0; j < M; j++) {
            maze[i][j] = s[j] - '0';
        }
    }
}

int BFS(void) {
    front = rear = 0;
    Queue[rear++] = (node_t){ 0, 0 };
    visited[0][0] = 1;
    dist[0][0] = 1; 

    while (front != rear) {
        node_t curr = Queue[front++];
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;  
            if (maze[nr][nc] == 0 || visited[nr][nc]) continue;    

            visited[nr][nc] = 1;
            dist[nr][nc] = dist[curr.r][curr.c] + 1;
            Queue[rear++] = (node_t){ nr, nc };
        }
    }
    return dist[N - 1][M - 1];
}

int main(void) {
    inputDataA();                
    printf("%d\n", BFS());      
    return 0;
}
