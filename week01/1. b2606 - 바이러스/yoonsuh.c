#include <stdio.h>
#include <stdlib.h>

#define MAX 101

int N;              
int M;               
int adj[MAX][MAX];  
int visited[MAX];  
int count_infected = 0;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= N; i++) {
        if (adj[v][i] && !visited[i]) {
            count_infected++;
            dfs(i);
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%d", &M);

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a][b] = 1;
        adj[b][a] = 1;
    }

    dfs(1);

    printf("%d\n", count_infected);

    return 0;
}
