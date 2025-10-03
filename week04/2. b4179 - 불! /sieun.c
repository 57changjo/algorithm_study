#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_N (1000+2)
int R, C;
int sR, sC;
int map[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
int fire[MAX_N][MAX_N];
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };
int front, rear;
typedef struct _node {
    int r, c;
}node_t;
node_t Queue[MAX_N * MAX_N];

void inputData(void) {
    scanf("%d %d", &R, &C);
    char temp[MAX_N];
    for (int i = 1; i <= R; i++) {
        scanf("%s", temp + 1);
        for (int j = 1; j <= C; j++) {
            if (temp[j] == '#') {
                map[i][j] = 0; // 벽
            }
            if (temp[j] == '.') {
                map[i][j] = 1; // 지나갈 수 있는
            }
            if (temp[j] == 'J') {
                map[i][j] = 1;
                sR = i; sC = j;
            }
            if (temp[j] == 'F') {
                map[i][j] = 2; // 불
            }
        }
    }
}

void BFS_fire(void) {
    front = rear = 0;
    node_t curr = { 0 };
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] == 2) {
                Queue[rear++] = (node_t){ i, j };
                fire[i][j] = 1; // 1부터 시작
            }
            else {
                fire[i][j] = INT_MAX;
            }
        }
    }

    while (front != rear) {
        curr = Queue[front++];
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (map[nr][nc] == 0) {
                continue;
            }
            if ((map[nr][nc] == 1) && fire[nr][nc] == INT_MAX) {
                Queue[rear++] = (node_t){ nr, nc };
                fire[nr][nc] = fire[curr.r][curr.c] + 1;
            }
        }
    }
}

int BFS_miroh(void) {
    front = rear = 0;
    Queue[rear++] = (node_t){ sR, sC };
    vis[sR][sC] = 1;
    node_t curr = { 0 };
    
    while (front != rear) {
        curr = Queue[front++];
        // 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.
        if (curr.r == 1 || curr.c == 1 || curr.r == R || curr.c == C) {
            return vis[curr.r][curr.c];
        }
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if ((map[nr][nc] == 1) && !vis[nr][nc] && (vis[curr.r][curr.c] + 1 < fire[nr][nc])) {
                Queue[rear++] = (node_t){ nr, nc };
                vis[nr][nc] = vis[curr.r][curr.c] + 1;
            }
        }
    }
    return -1;
}

int main(void) {
    inputData();
    BFS_fire();
    int result = BFS_miroh();
    if (result == -1) {
        printf("IMPOSSIBLE\n");
    }
    else {
        printf("%d\n", result);
    }
    printData();
    return 0;
}

#endif
