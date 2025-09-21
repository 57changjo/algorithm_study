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
