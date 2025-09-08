// 2번 - 오답
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (1000 + 1)
#define MAX_M (MAX_N*(MAX_N-1)/2 + 1)

int N, M;
int connect[MAX_M][2];
int Queue[MAX_N];
int front, rear;
int visited[MAX_N];
int group;

void inputData(void) {
    for (int i = 1; i <= M; ++i) { // 배열초기화
        for (int j = 0; j < 2; ++j) {
            connect[i][j] = 0;
        }
    }
    for (int j = 1; j <= N; ++j) {
        visited[j] = 0;
    }
    for (int j = 1; j < MAX_N; ++j) { //큐 초기화
        Queue[j] = 0;
    }
    
    (void)scanf("%d %d", &N, &M);
    for (int i = 1; i <= M; ++i) {
        (void)scanf("%d %d", &connect[i][0], &connect[i][1]);
    }
}
void printData(void) {
    for (int i = 1; i <= M; ++i) {
        printf("%d %d\n", connect[i][0], connect[i][1]);
    }
}
void BFS(int start) {
    front = rear = 0;
    int curr = 0;

    Queue[rear++] = start;
    visited[start] = 1;

    while (front != rear) {
        curr = Queue[front++];

        for (int i = 1; i <= M; ++i) {
            if ((curr == connect[i][0]) && !visited[connect[i][1]]) {
                int c = connect[i][1];
                Queue[rear++] = c;
                visited[c] = 1;
            }
            else if ((curr == connect[i][1]) && !visited[connect[i][0]]) {
                int c = connect[i][0];
                Queue[rear++] = c;
                visited[c] = 1;
            }
        }
    }
}
int main(void) {
    int T = 0;
    (void)freopen("b11724.txt", "r", stdin);
    (void)scanf("%d", &T);
    while (T--) {
        inputData();
        printData();
        for (int i = 1; i <= M; ++i) {
            for (int j = 0; j < 2; ++j) {
                int num = connect[i][j];
                if (!visited[num]) {
                    BFS(num);
                    group++;
                }
            }
        }
        printf("group: %d\n", group);
        group = 0;
    }

    return 0;
}
#endif
