// 1번
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_compN (100)
#define MAX_connN (MAX_compN*MAX_compN/2)

int compNum;
int connNum;
int cnt;
int front, rear;
int Queue[MAX_compN];

int connect[MAX_connN + 1][2];
int visited[MAX_compN + 1];

void inputData(void) {
    (void)scanf("%d", &compNum); //100이하 양의 정수
    (void)scanf("%d", &connNum); //연결쌍 수
    for (int i = 1; i <= connNum; ++i) {
        (void)scanf("%d %d", &connect[i][0], &connect[i][1]);
    }
}
void printData(void) {
    for (int i = 1; i <= connNum; ++i) {
        printf("%d %d\n", connect[i][0], connect[i][1]);
    }
}
int BFS() {
    front = rear = 0;
    int curr = 0;

    Queue[rear++] = 1; //computer number 1
    visited[1] = 1;

    while (front != rear) {
        curr = Queue[front++];

        for (int i = 1; i <= connNum; ++i) {
            if (curr == connect[i][0]) { //connect[i][0]가 큐에 없을 때
                int c = connect[i][1];
                if (!visited[c]) {
                    Queue[rear++] = c;
                    visited[c] = 1;
                    cnt++;

                    //connect[i][0] = 0; //반복문으로 queue를 확인하고, queue에 없으면 cnt++ 해야함
                    //connect[i][1] = 0;
                }

            }
            else if (curr == connect[i][1]) {
                int c = connect[i][0];
                if (!visited[c]) {
                    Queue[rear++] = c;
                    visited[c] = 1;
                    cnt++;

                    //connect[i][0] = 0;
                    //connect[i][1] = 0;
                }

            }
        }
    }
    return cnt;
}
int main(void) {

    //(void)freopen("b2606.txt", "r", stdin);
    inputData();
    //printData();
    printf("%d\n", BFS());
    return 0;
}
#endif
