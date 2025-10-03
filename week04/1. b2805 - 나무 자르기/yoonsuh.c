#include <stdio.h>

#define MAX 1000000

long long trees[MAX];  

int main() {
    int N;               
    long long M;         
    scanf("%d %lld", &N, &M);

    long long maxH = 0;
    for (int i = 0; i < N; i++) {
        scanf("%lld", &trees[i]);
        if (trees[i] > maxH) maxH = trees[i];
    }

    long long low = 0, high = maxH;
    long long ans = 0;

    while (low <= high) {
        long long mid = (low + high) / 2;
        long long sum = 0;

        for (int i = 0; i < N; i++) {
            if (trees[i] > mid) {
                sum += trees[i] - mid;
            }
        }

        if (sum >= M) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    printf("%lld\n", ans);
    return 0;
}
