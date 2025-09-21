// j1161 - 하노이1
// n == 3 동작
/* general 동작, think about recursion
1. Move (n-1) disc from P1 to P2
2. Move 1 disc from P1 to P3
3. Move (n-1) disc from P2 to P3
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void move(int n, int from, int to) {
    printf("%d : %d -> %d\n", n, from, to);
}

// num of disc, start point, middle point, target point
void hanoi(int n, int from, int by, int to) {
    // terminate condition
    if (n == 1)
        move(n, from, to);
    else {
        hanoi(n - 1, from, to, by);
        move(n, from, to);
        hanoi(n - 1, by, from, to);
    }
}

int main() {
    int i = 0;
    // pillars
    int from = 1, by = 2, to = 3;

    scanf("%d", &i);
    hanoi(i, from, by, to);

    return 0;
}
#endif


// b7795 먹을 것인가 먹힐 것인가
#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20000
int N, M;
int arra[MAX];
int arrb[MAX];

void inputData(void) {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arra[i]);
    }
    for (int i = 0; i < M; i++) {
        scanf("%d", &arrb[i]);
    }
}

int compare(const void* a, const void* b) {
    int x = *(const int*)a;
    int y = *(const int*)b;
    return (x > y) - (x < y);
}

// num 이상이 처음 나오는 위치 = num보다 작은 원소 개수
int BinarySearch_Lower(int num, int* ary, int low, int high) {
    int ret = high + 1; // 기본값: 전부 num보다 작으면 M 반환
    while (low <= high) {
        int mid = (low + high) / 2;
        if (ary[mid] < num) {
            low = mid + 1;
        }
        else {
            ret = mid;
            high = mid - 1;
        }
    }
    return ret;
}

int main(void) {
    //freopen("b7795.txt", "r", stdin);
    int T = 0;
    scanf("%d", &T);
    while (T--) {
        int result = 0;
        inputData();
        qsort(arrb, M, sizeof(arrb[0]), compare); // B만 정렬해도 됨

        for (int i = 0; i < N; i++) {
            int indexB = BinarySearch_Lower(arra[i], arrb, 0, M - 1);
            result += indexB;
        }
        printf("%d\n", result);
    }
    return 0;
}
#endif

// j1082 화염에서탈출(SLIKAR) 1s  4
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (50+2)
int R, C;
int sR, sC, eR, eC;
int map[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };
typedef struct _node {
    int r, c;
}node_t;
node_t Queue[MAX_N * MAX_N];
node_t Queue_fire[MAX_N * MAX_N];
int front, rear;

// 갈 수 있는 곳: 1, 불: 2, 바위: 3
void inputData(void) {
    scanf("%d %d", &R, &C);
    char temp[MAX_N] = { 0 };
    for (int i = 1; i <= R; i++) {
        scanf("%s", temp + 1);
        for (int j = 1; j <= C; j++) {
            if (temp[j] == '.') map[i][j] = 1;
            if (temp[j] == '*') map[i][j] = 2;
            if (temp[j] == 'X') map[i][j] = 3;
            if (temp[j] == 'S') {
                sR = i; sC = j; map[i][j] = 1;
            }
            if (temp[j] == 'D') {
                eR = i; eC = j; map[i][j] = 1;
            }
        }
    }
}

void printData(void) {
    printf("%d %d\n", sR, sC);
    printf("%d %d\n", eR, eC);
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void init_fire(void) {
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            if (map[i][j] == 2) {
                Queue_fire[rear++] = (node_t){ i, j };
            }
        }
    }
}

int BFS_fire(void) {
    front = rear = 0;
    node_t curr = { 0 };
    Queue[rear++] = (node_t){ sR, sC };
    init_fire();
    vis[sR][sC] = 1;
    int curr_time = 0; // 시간이 늘어나면 불이 붙는다.

    while (front != rear) {
        curr = Queue[front++];
        if (curr.r == eR && curr.c == eC) return vis[eR][eC] - 1;
        for (int i = 0; i < 4; i++) {
            int nr = curr.r + dr[i];
            int nc = curr.c + dc[i];
            if (map[nr][nc] && !vis[nr][nc]) {
                vis[nr][nc] = vis[curr.r][curr.c] + 1;
                Queue[rear++] = (node_t){ nr, nc };
            }
        }
    }
    return -1;
}


int main(void) {
    freopen("j1082.txt", "r", stdin);
    inputData();
    printData();

    int result = BFS_fire();

    if (result == -1) printf("impossible\n");
    else printf("%d\n", result);

    return 0;
}

#endif