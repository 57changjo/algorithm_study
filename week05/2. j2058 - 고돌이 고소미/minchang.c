#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX (25 + 2)
#define Q_MAX (MAX * MAX * MAX * MAX)

typedef struct node_t {
    int gdr, gdc; // 고돌이 위치
    int gsr, gsc; // 고소미 위치
    int time;     // 경과 시간
} node;

node Queue[Q_MAX];
int front, rear;

int N;
int gdr, gdc;
int gsr, gsc;
int gdhr, gdhc;
int gshr, gshc;

int map[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];

// 8방향 + 제자리
int dr[9] = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };
int dc[9] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };

void dataInput(void) {
    (void)scanf("%d", &N);
    (void)scanf("%d %d %d %d", &gdr, &gdc, &gdhr, &gdhc);
    (void)scanf("%d %d %d %d", &gsr, &gsc, &gshr, &gshc);

    memset(map, 1, sizeof(map));

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            (void)scanf("%d", &map[r][c]);
        }
    }
}

int is_adj(int r1, int c1, int r2, int c2) {
    if (r1 - 1 <= r2 && r2 <= r1 + 1 && c1 - 1 <= c2 && c2 <= c1 + 1) {
        return 1;
    }
    return 0;
}

int solve(void) {
    front = rear = 0;

    Queue[rear++] = (node){ gdr, gdc, gsr, gsc, 0 };
    visited[gdr][gdc][gsr][gsc] = 1;

    while (front != rear) {
        node curr = Queue[front++];

        if ((curr.gdr == gdhr && curr.gdc == gdhc) &&
            (curr.gsr == gshr && curr.gsc == gshc)) {
            return curr.time;
        }

        for (int i = 0; i < 9; i++) {
            int next_gdr = curr.gdr + dr[i];
            int next_gdc = curr.gdc + dc[i];

            for (int j = 0; j < 9; j++) {
                int next_gsr = curr.gsr + dr[j];
                int next_gsc = curr.gsc + dc[j];

                if (map[next_gdr][next_gdc] == 0 && map[next_gsr][next_gsc] == 0) {

					// 방문 예정인 좌표가 인접하면 continue
                    if (is_adj(next_gdr, next_gdc, next_gsr, next_gsc)) {
                        continue;
                    }

                    if (!visited[next_gdr][next_gdc][next_gsr][next_gsc]) {
                        visited[next_gdr][next_gdc][next_gsr][next_gsc] = 1;
                        Queue[rear++] = (node){ next_gdr, next_gdc, next_gsr, next_gsc, curr.time + 1 };
                    }
                }
            }
        }
    }
    return -1;
}

int main(void) {
    //(void)freopen("j2058.txt", "r", stdin);
    dataInput();
    int result = solve();
    printf("%d", result);
    return 0;
}

#endif
