#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1000

int N, M;
int adj[MAX_N + 1][MAX_N + 1];  
int visited[MAX_N + 1];

void dfs(int v) {
    visited[v] = 1;
    for (int u = 1; u <= N; u++) {
        if (adj[v][u] && !visited[u]) {
            dfs(u);
        }
    }
}

int main(void) {
    if (scanf("%d %d", &N, &M) != 2) return 0;

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            count++;
            dfs(i);
        }
    }

    printf("%d\n", count);

    return 0;
}
