#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define MAX_SIZE 100001

int N, K;
int MAP[MAX_SIZE];
int minTime = INT_MAX;
int Queue[MAX_SIZE*1000];
int front = 0, rear = 0;
int countWays = 0;

void bfs(int start) {
    Queue[rear++] = start;
    MAP[start] = 0;

    while (front != rear) {
        int current = Queue[front++];
        int currentTime = MAP[current];

        if (currentTime > minTime) continue;

        if (current == K) {
            if (currentTime < minTime) {
                minTime = currentTime;
                countWays = 1;
            }
            else if (currentTime == minTime) { countWays++; }
            continue;
        }

        int cand[3] = { current - 1, current + 1, current * 2 };
        for (int i = 0; i < 3; ++i) {
            int next = cand[i];

            int dup = 0;
            for (int j = 0; j < i; ++j) {
                if (cand[j] == next) {
                    dup = 1;
                    break;
                }
            }

            if (dup) continue;

            if (next >= 0 && next < MAX_SIZE) {
                if (MAP[next] == -1 || MAP[next] == currentTime + 1) {
                    MAP[next] = currentTime + 1;
                    Queue[rear++] = next;
                }
            }
        }
    }
}

void inputData(void) { (void)scanf("%d %d", &N, &K); }

int main(void) {
    //(void)freopen("b12851.txt", "r", stdin);
    for (int i = 0; i < MAX_SIZE; ++i) MAP[i] = -1;

    inputData();
    if (N == K) {
        printf("0\n1\n");
        return 0;
    }

    bfs(N);
    printf("%d\n%d\n", minTime, countWays);
    return 0;
}
#endif
