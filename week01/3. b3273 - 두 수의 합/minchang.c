#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_N (100000)
#define MAX_A (1000000)

int n;
int Nums[MAX_N];
int x;

void inputData(void) {
    //(void)freopen("b3273.txt", "r", stdin);
    (void)scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
        (void)scanf("%d", Nums+i);
    }

    (void)scanf("%d", &x);
}

void printData(int* ary, int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", ary[i]);
    }
    printf("\n");
}


int compInt(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int main(void) {
    inputData();
    //printData(Nums, n);
    
    qsort(Nums, n, sizeof(int), compInt);
    
    int cnt = 0;
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        int sum = Nums[left] + Nums[right];
        
        if (sum == x) {
            ++cnt;
            ++left;
            --right;
        } else if (sum < x) {
            ++left;
        } else {
            --right;
        }
    }
    
    printf("%d", cnt);
    return 0;
}
