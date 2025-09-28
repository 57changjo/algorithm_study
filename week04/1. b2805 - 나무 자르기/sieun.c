#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N 1000000
#define MAX_M 2000000000
int N, M;
int namu[MAX_N];

void inputData(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &namu[i]);
	}
}

int compare(const void* a, const void* b) {
	int x = *(const int*)a;
	int y = *(const int*)b;
	return (x > y) - (x < y);
}

long long get_trees(int height) {
    long long result = 0;
    for (int i = 0; i < N; i++) {
        if (namu[i] > height) {
            result += (long long)namu[i] - height;
        }
    }
    return result;
}

int cut_down_trees(int num, int* ary) {
    int low = 0, high = namu[N - 1];
    int ret = 0; // 기본값

    while (low <= high) {
        int mid = (low + high) / 2;
        long long trees = get_trees(mid);

        if (trees >= num) {
            ret = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return ret;
}


int main(void) {
    inputData();
    qsort(namu, N, sizeof(int), compare);
	  int result = cut_down_trees(M, namu);
    printf("%d\n", result);

	  return 0;
}
#endif
