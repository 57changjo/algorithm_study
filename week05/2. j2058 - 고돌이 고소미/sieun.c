// j2058 - 고돌이 고소미
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 25

typedef struct {
    int dr, dc;  // 고돌이 위치
    int sr, sc;  // 고소미 위치
    int time;    // 시간
} Node;

int N;
int map[MAX][MAX];
int visited[MAX][MAX][MAX][MAX];
Node queue[1000000];
int front, rear;

// 8방향 + 제자리
int dx[9] = { -1, 1, 0, 0, -1, -1, 1, 1, 0 };
int dy[9] = { 0, 0, -1, 1, -1, 1, -1, 1, 0 };

int inRange(int r, int c) {
    return (r >= 0 && r < N && c >= 0 && c < N);
}

int isFree(int r, int c) {
    return (map[r][c] == 0); // 0은 이동 가능, 1은 웅덩이
}

int isSafe(int dr, int dc, int sr, int sc) {
    // 겹치거나 인접하면 false
    if (dr == sr && dc == sc) return 0;
    if (abs(dr - sr) <= 1 && abs(dc - sc) <= 1) return 0;
    return 1;
}

int bfs(Node start, Node goal) {
    front = rear = 0;
    queue[rear++] = start;
    visited[start.dr][start.dc][start.sr][start.sc] = 1;

    while (front < rear) {
        Node cur = queue[front++];

        // 둘 다 도착 위치에 도달
        if (cur.dr == goal.dr && cur.dc == goal.dc &&
            cur.sr == goal.sr && cur.sc == goal.sc)
            return cur.time;

        // 고돌이 이동
        for (int i = 0; i < 9; i++) {
            int nd_r = cur.dr + dx[i];
            int nd_c = cur.dc + dy[i];
            if (!inRange(nd_r, nd_c) || !isFree(nd_r, nd_c)) continue;

            // 고소미 이동
            for (int j = 0; j < 9; j++) {
                int ns_r = cur.sr + dx[j];
                int ns_c = cur.sc + dy[j];
                if (!inRange(ns_r, ns_c) || !isFree(ns_r, ns_c)) continue;

                // 서로 교차하는 경우 금지
                if (nd_r == cur.sr && nd_c == cur.sc &&
                    ns_r == cur.dr && ns_c == cur.dc)
                    continue;

                // 인접 또는 겹치는 경우 금지
                if (!isSafe(nd_r, nd_c, ns_r, ns_c))
                    continue;

                if (!visited[nd_r][nd_c][ns_r][ns_c]) {
                    visited[nd_r][nd_c][ns_r][ns_c] = 1;
                    queue[rear++] = (Node){ nd_r, nd_c, ns_r, ns_c, cur.time + 1 };
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d", &N);

    Node start = { 0 }, goal = { 0 };
    int gr, gc, gtr, gtc;
    int sr, sc, str, stc;

    // 고돌이: 시작, 도착
    scanf("%d %d %d %d", &gr, &gc, &gtr, &gtc);
    // 고소미: 시작, 도착
    scanf("%d %d %d %d", &sr, &sc, &str, &stc);

    // 1-based → 0-based
    gr--; gc--; gtr--; gtc--;
    sr--; sc--; str--; stc--;

    // 지도 입력 (0: 가능, 1: 웅덩이)
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            scanf("%d", &map[i][j]);

    start.dr = gr; start.dc = gc;
    start.sr = sr; start.sc = sc;
    start.time = 0;

    goal.dr = gtr; goal.dc = gtc;
    goal.sr = str; goal.sc = stc;

    memset(visited, 0, sizeof(visited));

    int ans = bfs(start, goal);
    printf("%d\n", ans);
    return 0;
}

#endif
