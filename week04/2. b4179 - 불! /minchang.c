#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (1000 + 2)

typedef struct node_t {
    int r, c;
} node;

int R, C;
int jr, jc;

int ffront, ffrear;
int jfront, jfrear;

node fQueue[MAX * MAX];
node jQueue[MAX * MAX];

char map[MAX][MAX];
int  fire[MAX][MAX];
int  jihun[MAX][MAX];

int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0,-1, 1 };

int inb(int r, int c) {
    return (1 <= r && r <= R && 1 <= c && c <= C);
}

void inputData(void) {
    ffront = ffrear = 0;
    jfront = jfrear = 0;

    (void)scanf("%d %d", &R, &C);
    for (int i = 1; i <= R; ++i) {
        (void)scanf("%s", &map[i][1]);
        for (int j = 1; j <= C; ++j) {
            if (map[i][j] == 'J') {
                jr = i; jc = j;
                jihun[i][j] = 1;
            }
            else if (map[i][j] == 'F') {
                fQueue[ffrear].r = i;
                fQueue[ffrear++].c = j;
                fire[i][j] = 1;
            }
        }
    }
}

int main(void) {
    //(void)freopen("b4179.txt", "r", stdin);
    inputData();

    while (ffront != ffrear) {
        node curr = fQueue[ffront++];
        int r = curr.r;
        int c = curr.c;
        int t = fire[r][c];

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (!inb(nr, nc)) continue;
            if (map[nr][nc] == '#') continue;
            if (fire[nr][nc] != 0) continue;
            fire[nr][nc] = t + 1;
            fQueue[ffrear++] = (node){ nr, nc };
        }
    }

    jQueue[jfrear++] = (node){ jr, jc };
    if (jr == 1 || jr == R || jc == 1 || jc == C) {
        printf("%d\n", jihun[jr][jc]);
        return 0;
    }

    while (jfront != jfrear) {
        node curr = jQueue[jfront++];
        int r = curr.r;
        int c = curr.c;
        int t = jihun[r][c];

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];
            if (!inb(nr, nc)) continue;
            if (map[nr][nc] == '#') continue;
            if (jihun[nr][nc] != 0) continue;
            if (fire[nr][nc] != 0 && fire[nr][nc] <= t + 1) continue;

            jihun[nr][nc] = t + 1;
            jQueue[jfrear++] = (node){ nr, nc };

            if (nr == 1 || nr == R || nc == 1 || nc == C) {
                printf("%d", jihun[nr][nc]);
                return 0;
            }
        }
    }

    printf("IMPOSSIBLE");
    return 0;
}
#endif
