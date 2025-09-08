// 3번
//시간초과
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_N (100000)
int n;
int x;
int num[MAX_N];

void inputData(void) {
    (void)scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        (void)scanf("%d", &num[i]);
    }
    (void)scanf("%d", &x);
}
void printData(void) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
int main(void) {
    (void)freopen("b3273.txt", "r", stdin);
    inputData();
    printData();

    int cnt = 0;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((num[i] + num[j]) == x) {
                cnt++;
                break; //모두 다른 숫자니까
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
#endif
//투 포인터
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) ( sizeof(a)/sizeof(a[0]) )

#define MAX_N (100000)
int n;
int x;
int num[MAX_N];

void inputData(void) {
    (void)scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        (void)scanf("%d", &num[i]);
    }
    (void)scanf("%d", &x);
}
void printData(void) {
    for (int i = 0; i < n; ++i) {
        printf("%d ", num[i]);
    }
    printf("\n");
}
int compInt(const void* ap, const void* bp) {
    int a = *((int*)ap);
    int b = *((int*)bp);
    return (a > b) - (a < b);
}
int main(void) {
    (void)freopen("b3273.txt", "r", stdin);
    inputData();
    printData();

    int cnt = 0;
    int left = 0;
    int right = n - 1;
    int sum = 0;

    qsort(num, n, sizeof(num[0]), compInt);
    while (left < right) { //서로 다른 두 수니까 등호 없음
        sum = num[left] + num[right];
        if (sum == x) {
            left++;
            right--;
            cnt++;
        }
        else if (sum > x) {
            right--;
        }
        else {// sum < x
            left++;
        }
    }

    printf("%d\n", cnt);
    return 0;
}
#endif
