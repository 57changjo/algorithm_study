// j1082 화염에서탈출(SLIKAR)
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (50+2)
#define MAX_INT 1215752192
int R, C;
int sR, sC, eR, eC;
int map[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
int fire[MAX_N][MAX_N];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
typedef struct _node {
    int r, c;
}node_t;
node_t Queue[MAX_N * MAX_N];
node_t Queue_fire[MAX_N * MAX_N];
int front, rear;

// 갈 수 있는 곳: 1, 불: 2, 바위: 3, 도착점: 4
void inputData(void) {
    scanf("%d %d", &R, &C);
    char temp[MAX_N] = { 0 };
    for (int i = 1; i <= R; i++) {
        scanf("%s", temp + 1);
        for (int j = 1; j <= C; j++) {
            if (temp[j] == '.') map[i][j] = 1;
            if (temp[j] == '*') map[i][j] = 2;
            if (temp[j] == 'X') map[i][j] = 3;
            if (temp[j] == 'S') {
                sR = i; sC = j; map[i][j] = 1;
            }
            if (temp[j] == 'D') {
                eR = i; eC = j; map[i][j] = 1;
            }
        }
    }
}

void printData(void) {
    printf("%d %d\n", sR, sC);
    printf("%d %d\n", eR, eC);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (fire[i][j] == MAX_INT) printf("  #");
            else printf("%3d", fire[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            printf("%3d", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            printf("%3d", vis[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void init_fire(void) {
    front = rear = 0;
    node_t curr = { 0 };
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] == 2) {
                Queue_fire[rear++] = (node_t){ i, j };
                fire[i][j] = 1; // 불 번진 시간, 1부터 시작
            }
            else fire[i][j] = MAX_INT;
        }
    }    

    while (front != rear) {
        curr = Queue_fire[front++];
        //printf("currfire: %d %d\n", curr.r, curr.c);
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (nr == eR && nc == eC) continue;
            if ((map[nr][nc]==1) && fire[nr][nc] == MAX_INT) {
                fire[nr][nc] = fire[curr.r][curr.c] + 1;
                Queue_fire[rear++] = (node_t){ nr, nc };
            }
        }
    }
}

int BFS_fire(void) {
    front = rear = 0;
    node_t curr = { 0 };
    Queue[rear++] = (node_t){ sR, sC };
    vis[sR][sC] = 1; // visit 시간, 1부터 시작

    while (front != rear) {
        curr = Queue[front++];
        //printf("curr: %d %d\n", curr.r, curr.c);
        if (curr.r == eR && curr.c == eC) return vis[curr.r][curr.c] - 1;
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if ((map[nr][nc]==1) && !vis[nr][nc] && (vis[curr.r][curr.c] + 1 < fire[nr][nc])) {
                vis[nr][nc] = vis[curr.r][curr.c] + 1;
                Queue[rear++] = (node_t){ nr, nc };
            }
        }
    }
    return -1;
}


int main(void) {
    //freopen("j1082.txt", "r", stdin);
    inputData();

    init_fire();
    int result = BFS_fire();

    if (result == -1) printf("impossible\n");
    else printf("%d\n", result);
    //printData();
    return 0;
}

#endif
