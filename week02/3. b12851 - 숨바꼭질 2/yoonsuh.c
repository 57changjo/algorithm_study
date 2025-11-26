#include <stdio.h>

#define MAX 100000

int N, K;
int q[300000];        
int dist[MAX + 1];    

int main() {
    scanf("%d %d", &N, &K);

 
    if (N >= K) {
        printf("%d\n1\n", N - K);
        return 0;
    }

    // dist 초기화
    for (int i = 0; i <= MAX; i++) {
        dist[i] = -1;
    }

    int front = 0, rear = 0;
    q[rear++] = N;
    dist[N] = 0;

    int minTime = -1;
    int count = 0;

    while (front < rear) {
        int x = q[front++];

        if (minTime != -1 && dist[x] > minTime) break;

        if (x == K) {
            if (minTime == -1) {
                minTime = dist[x];
                count = 1;
            } else if (dist[x] == minTime) {
                count++;
            }
            continue;
        }

        int next[3] = { x - 1, x + 1, x * 2 };

        for (int i = 0; i < 3; i++) {
            int nx = next[i];
            if (nx < 0 || nx > MAX) continue;

            // 안갔거나 한번더
            if (dist[nx] == -1 || dist[nx] == dist[x] + 1) {
                dist[nx] = dist[x] + 1;
                q[rear++] = nx;
            }
        }
    }

    printf("%d\n%d\n", minTime, count);
    return 0;
}
