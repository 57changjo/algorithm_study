// 1
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N;
int P[1001];

int compInt(const void * ap, const void* bp) {
    int a = *(int*)ap;
    int b = *(int*)bp;
    return (a - b) - (b - a);
}

int main(void) {
    (void)freopen("b11399.txt", "r", stdin);
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> P[i];
    }
    qsort(P, N, sizeof(P[0]), compInt);

    /*for (int i = 1; i <= N; ++i) {
        cout << P[i];
    }*/

    int sum = 0;
    for (int i = 0; i < N; ++i) {
        sum += P[i] * (N - i);
    }
    cout << sum;

    return 0;
}

#endif
