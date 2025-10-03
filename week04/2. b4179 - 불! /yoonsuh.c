#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (1000 + 2)

typedef struct {
    int r, c;
} node_t;

int R, C;
char map[MAX_N][MAX_N];     
int fireTime[MAX_N][MAX_N]; 
int jihunTime[MAX_N][MAX_N]; 

node_t Queue[MAX_N * MAX_N];   // 지훈이 큐
int front, rear;

node_t QueueF[MAX_N * MAX_N];  // 불 큐
int frontF, rearF;

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

void inputData(void) {
    scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; i++) {
        scanf("%s", map[i] + 1);
    }
}

void fireBFS(void) {
    while (frontF != rearF) {
        node_t cur = QueueF[frontF++];
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            if (nr < 1 || nr > R || nc < 1 || nc > C) continue;
            if (map[nr][nc] == '#' || fireTime[nr][nc] != 0) continue;
            fireTime[nr][nc] = fireTime[cur.r][cur.c] + 1;
            QueueF[rearF++] = (node_t){ nr, nc };
        }
    }
}

int jihunBFS(void) {
    while (front != rear) {
        node_t cur = Queue[front++];
        for (int i = 0; i < 4; i++) {
            int nr = cur.r + dr[i];
            int nc = cur.c + dc[i];
            // 맵 벗어나면 탈출성공
            if (nr < 1 || nr > R || nc < 1 || nc > C) {
                return jihunTime[cur.r][cur.c];
            }
            if (map[nr][nc] == '#' || jihunTime[nr][nc] != 0) continue;
            
            //  불이 없거나 먼저 도착해야함
            if (fireTime[nr][nc] != 0 && fireTime[nr][nc] <= jihunTime[cur.r][cur.c] + 1) continue;

            jihunTime[nr][nc] = jihunTime[cur.r][cur.c] + 1;
            Queue[rear++] = (node_t){ nr, nc };
        }
    }
    return -1; // 탈출 불가
}

int main(void) {
    inputData();

    
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] == 'F') {
                QueueF[rearF++] = (node_t){ i, j };
                fireTime[i][j] = 1; 
            }
            else if (map[i][j] == 'J') {
                Queue[rear++] = (node_t){ i, j };
                jihunTime[i][j] = 1; 
            }
        }
    }
    fireBFS();
    int ans = jihunBFS();
    if (ans == -1) printf("IMPOSSIBLE\n");
    else printf("%d\n", ans);
    return 0;
}
