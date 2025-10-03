#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int N;
int maxh = 0;
int tree[1000000];
ll M;

void inputData(void) {
	(void)scanf("%d %lld", &N, &M);

    for (int i = 0; i < N; ++i) {
        (void)scanf("%d", &tree[i]);
        if (tree[i] > maxh) {
            maxh = tree[i];
        }
    }
}

int main(void) {
    (void)freopen("b2805.txt", "r", stdin);
	inputData();

    int lo = 0;
    int hi = maxh;
    int ans = 0;

    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        ll currSum = 0;

        for (int i = 0; i < N; ++i) {
            if (tree[i] > mid) {
                currSum += (ll)(tree[i] - mid);
                if (currSum >= M) break;
            }
        }

        if (currSum >= M) {
            ans = mid;
            lo = mid + 1;
        }
        else {
            hi = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}

#endif
