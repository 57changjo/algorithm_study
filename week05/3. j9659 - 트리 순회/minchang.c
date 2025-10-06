#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N (1000 + 1)

int N;
int cid, pid;
int x;
int adj[MAX_N][MAX_N];
int parent[MAX_N];
int visited[MAX_N];

int x2root;
int numofchild;
int x2cdist;
int x2farnodedist;

void dataInput(void) {
    (void)scanf("%d", &N);
    for (int i = 1; i < N; ++i) {
        (void)scanf("%d %d", &cid, &pid);
        adj[pid][cid] = 1;
        parent[cid] = pid;
    }
    (void)scanf("%d", &x);
}

void findxtoroot(int node, int dist) {
    if (node == 1) {
        x2root = dist;
        return;
    }
    findxtoroot(parent[node], dist + 1);
}

void findnumofchild(int node) {
    numofchild++;
    for (int i = 1; i <= N; ++i) {
        if (adj[node][i]) {
            findnumofchild(i);
        }
    }
}

void findx2childdist(int node, int dist) {
    int is_leaf = 1;
    for (int i = 1; i <= N; ++i) {
        if (adj[node][i]) {
            is_leaf = 0;
            findx2childdist(i, dist + 1);
        }
    }
    if (is_leaf && (dist > x2cdist)) {
        x2cdist = dist;
    }
}

void findx2farnodedist(int node, int dist) {
    if (dist > x2farnodedist) {
        x2farnodedist = dist;
    }

	// 자식 노드 탐색
    for (int i = 1; i <= N; ++i) {
        if (adj[node][i] && !visited[i]) {
            visited[i] = 1;
            findx2farnodedist(i, dist + 1);
        }
    }

	// 부모 노드 탐색
    if (parent[node] != 0 && !visited[parent[node]]) {
        visited[parent[node]] = 1;
        findx2farnodedist(parent[node], dist + 1);
    }
}

void printResult(void) {
    printf("%d\n", x2root);
    printf("%d\n", numofchild);
    printf("%d\n", x2cdist);
    printf("%d\n", x2farnodedist);
}

int main(void) {
    //(void)freopen("j9659.txt", "r", stdin);
    dataInput();

    findxtoroot(x, 0);
    findnumofchild(x);
    findx2childdist(x, 0);

    visited[x] = 1;
    findx2farnodedist(x, 0);
    printResult();

    return 0;
}
#endif
