#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

int adj[MAX][MAX];
int adj_size[MAX];
int dist[MAX];
int visited[MAX];
int parent_of[MAX];
int queue[MAX];

// (1) 루트와의 거리 계산 (BFS) - 모든 노드 계산
void bfs_root(int start) {
    int front = 0, rear = 0;
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));

    visited[start] = 1;
    //dist[start] = 0;
    queue[rear++] = start;

    while (front < rear) {
        int cur = queue[front++];
        for (int i = 0; i < adj_size[cur]; i++) {
            int next = adj[cur][i];
            if (!visited[next]) {
                visited[next] = 1;
                dist[next] = dist[cur] + 1;
                queue[rear++] = next;
            }
        }
    }
}

// (2) 자손 노드 개수 계산 (DFS)
int count_descendants(int node, int parent) {
    int cnt = 1; // 자기 자신 포함
    for (int i = 0; i < adj_size[node]; i++) {
        int next = adj[node][i];
        if (next == parent) continue;
        cnt += count_descendants(next, node);
    }
    return cnt;
}

// (3) 가장 먼 자손과의 거리 (DFS)
int farthest_descendant(int node, int parent, int depth) {
    int max_depth = depth;
    for (int i = 0; i < adj_size[node]; i++) {
        int next = adj[node][i];
        if (next == parent) continue;
        int d = farthest_descendant(next, node, depth + 1);
        if (d > max_depth) max_depth = d;
    }
    return max_depth;
}

// (4) 가장 먼 노드 거리 (BFS)
int farthest_node(int start) {
    int queue[MAX], dist_local[MAX], visited_local[MAX];
    int front = 0, rear = 0;
    memset(visited_local, 0, sizeof(visited_local));
    memset(dist_local, 0, sizeof(dist_local));

    visited_local[start] = 1;
    dist_local[start] = 0;
    queue[rear++] = start;
    int maxd = 0;

    while (front < rear) {
        int cur = queue[front++];
        for (int i = 0; i < adj_size[cur]; i++) {
            int next = adj[cur][i];
            if (!visited_local[next]) {
                visited_local[next] = 1;
                dist_local[next] = dist_local[cur] + 1;
                if (dist_local[next] > maxd) maxd = dist_local[next];
                queue[rear++] = next;
            }
        }
    }
    return maxd;
}

int main(void) {
    int N;
    if (scanf("%d", &N) != 1) return 0;

    memset(adj_size, 0, sizeof(adj_size));
    memset(parent_of, 0, sizeof(parent_of));

    for (int i = 0; i < N - 1; i++) {
        int cid, pid;
        scanf("%d %d", &cid, &pid);
        // 인접 리스트 형태
        adj[cid][adj_size[cid]++] = pid;
        adj[pid][adj_size[pid]++] = cid;
        // 부모 정보 저장
        parent_of[cid] = pid;
    }

    int x;
    scanf("%d", &x);

    // 1) 루트와의 거리
    bfs_root(1);
    printf("%d\n", dist[x]);

    // 2) 본인 포함 자손 개수 (초기 parent로 parent_of[x] 전달)
    printf("%d\n", count_descendants(x, parent_of[x]));

    // 3) 가장 먼 자손과의 거리
    printf("%d\n", farthest_descendant(x, parent_of[x], 0));

    // 4) 가장 먼 노드와의 거리
    printf("%d\n", farthest_node(x));

    return 0;
}
#endif
