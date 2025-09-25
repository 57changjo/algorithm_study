#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int cmpInt(const void* ap, const void* bp) {
    int a = *(const int*)ap;
    int b = *(const int*)bp;
    return (a > b) - (a < b);
}


int lower_bound(int* arr, int n, int key) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (arr[mid] >= key) {
            hi = mid;
        }
        else {
            lo = mid + 1;
        }
    }
    return lo; // key보다 작은 원소의 개수
}

void inputSizes(int* N, int* M) {
    (void)scanf("%d %d", N, M);
}

void inputData(int N, int M, int* A, int* B) {
    for (int i = 0; i < N; ++i) {
        (void)scanf("%d", A + i);
    }
    for (int i = 0; i < M; ++i) {
        (void)scanf("%d", B + i);
    }
}

int main(void) {
    int T;
    //(void)freopen("b7795.txt", "r", stdin);
    (void)scanf("%d", &T);

    while (T--) {
        int N, M;
        inputSizes(&N, &M);

        int* A = (int*)malloc(sizeof(int) * N);
        int* B = (int*)malloc(sizeof(int) * M);
        if (!A || !B) {
            free(A);
            free(B);
            return 0;
        }

        inputData(N, M, A, B);

        qsort(B, M, sizeof(int), cmpInt);

        int rst = 0;
        for (int i = 0; i < N; ++i) {
            int cnt = lower_bound(B, M, A[i]); // B에서 A[i]보다 작은 원소 수
            rst += cnt;
        }

        printf("%d\n", rst);

        free(A);
        free(B);
    }
    return 0;
}
#endif
