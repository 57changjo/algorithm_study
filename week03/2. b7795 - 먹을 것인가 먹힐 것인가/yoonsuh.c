#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

void inputArray(int *arr, int size) {
    for (int i = 0; i < size; i++) scanf("%d", &arr[i]);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int A[n], B[m];

        inputArray(A, n);
        inputArray(B, m);

        qsort(A, n, sizeof(int), cmp);
        qsort(B, m, sizeof(int), cmp);

        int result = 0;
        int j = 0;

        for (int i = 0; i < n; i++) {
            while (j < m && B[j] < A[i]) j++;
            result += j; 

        printf("%d\n", result);
    }

    return 0;
}
