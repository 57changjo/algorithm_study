#include <stdio.h>

#define MAX 1001

int tree[MAX][MAX];   // 자식 노드 저장
int count[MAX];       // 각 노드 자식 개수
int depth[MAX];       // 루트와 거리
int subtree[MAX];     // 자기 포함 자손 개수
int maxDist[MAX];     // 가장 먼 자손 거리
int N;

// DFS 루트부터 시작!
void dfs(int cur) {
    subtree[cur] = 1;     
    maxDist[cur] = 0;

    for (int i = 0; i < count[cur]; i++) {
        int next = tree[cur][i];
        depth[next] = depth[cur] + 1; 
        dfs(next);

        subtree[cur] += subtree[next]; 
        if (maxDist[next] + 1 > maxDist[cur])
            maxDist[cur] = maxDist[next] + 1; 
    }
}


int maxDistanceFromNode(int x) {
    int maxD = maxDist[x]; 

    int cur = x;
    int distToRoot = 0; 
    while (cur != 1) {  
        int p;
        for (p = 1; p <= N; p++) {
            for (int i = 0; i < count[p]; i++) {
                if (tree[p][i] == cur) goto found;
            }
        }
        found:
        cur = p;
        distToRoot++;
        int maxSibling = 0;
        for (int i = 0; i < count[cur]; i++) {
            int c = tree[cur][i];
            if (c != x) { 
                if (maxDist[c] + 1 > maxSibling)
                    maxSibling = maxDist[c] + 1;
            }
        }
        if (distToRoot + maxSibling > maxD) maxD = distToRoot + maxSibling;
        x = cur;
    }

    return maxD;
}

int main() {
    scanf("%d", &N);
    for (int i = 0; i <= N; i++) count[i] = 0;

    for (int i = 0; i < N - 1; i++) {
        int cid, pid;
        scanf("%d %d", &cid, &pid);
        tree[pid][count[pid]++] = cid;
    }

    int x;
    scanf("%d", &x);

    depth[1] = 0;
    dfs(1); 

    int dist_root = depth[x];
    int descendants = subtree[x];
    int max_child_dist = maxDist[x];
    int max_total_dist = maxDistanceFromNode(x);

    printf("%d\n", dist_root);
    printf("%d\n", descendants);
    printf("%d\n", max_child_dist);
    printf("%d\n", max_total_dist);

    return 0;
}
