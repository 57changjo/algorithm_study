
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define MAX 50

typedef struct node_t {
    int r, c;
}node;


int R, C;
char Map[MAX][MAX + 1];
int fireT[MAX][MAX];
int arrivedTime[MAX][MAX];

int sr, sc;
int hr, hc;
int dr[4] = { -1, 1, 0, 0 };
int dc[4] = { 0, 0, -1, 1 };

int inBounds(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

void inputData(void) {
    scanf("%d %d", &R, &C);

    for (int i = 0; i < R; i++) {
        scanf("%s", Map[i]);
        for (int j = 0; j < C; j++) {
            fireT[i][j] = INT_MAX;
            arrivedTime[i][j] = INT_MAX;
            if (Map[i][j] == 'S') { sr = i; sc = j; }
            if (Map[i][j] == 'D') { hr = i; hc = j; }
        }
    }
}

int main(void) {
    // freopen("b1082.txt", "r", stdin);
    inputData();

    // 불 BFS
    node FQueue[MAX * MAX];
    int ffront = 0, frear = 0;

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (Map[i][j] == '*') {
                fireT[i][j] = 0;
                FQueue[frear++] = (node){ i, j };
            }
        }
    }

    while (ffront < frear) {
        node cur = FQueue[ffront++];
        int r = cur.r, c = cur.c;
        int t = fireT[r][c];

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (!inBounds(nr, nc)) continue;
            if (Map[nr][nc] == 'X') continue; // 바위
            if (Map[nr][nc] == 'D') continue; // 집에는 불이 번지지 않음
            if (fireT[nr][nc] != INT_MAX) continue;
            fireT[nr][nc] = t + 1;
            FQueue[frear++] = (node){ nr, nc };
        }
    }

    // 재우 BFS
    node JQueue[MAX * MAX];
    int jfront = 0, jrear = 0;

    arrivedTime[sr][sc] = 0;
    JQueue[jrear++] = (node){ sr, sc };

    int rst = -1;

    while (jfront < jrear) {
        node curr = JQueue[jfront++];
        int r = curr.r, c = curr.c;
        int t = arrivedTime[r][c];

        for (int k = 0; k < 4; k++) {
            int nr = r + dr[k], nc = c + dc[k];
            if (!inBounds(nr, nc)) continue;
            if (Map[nr][nc] == 'X') continue;

            if (Map[nr][nc] == 'D') {
                rst = t + 1;
                jfront = jrear;
                break;
            }

            if (Map[nr][nc] == '.' || Map[nr][nc] == 'S') {
                if (arrivedTime[nr][nc] == INT_MAX && fireT[nr][nc] > t + 1) {
                    arrivedTime[nr][nc] = t + 1;
                    JQueue[jrear++] = (node){ nr, nc };
                }
            }
        }
    }

    if (rst == -1) {
        printf("impossible\n");
    }
    else {
        printf("%d\n", rst);
    }

    return 0;
}
#endif
