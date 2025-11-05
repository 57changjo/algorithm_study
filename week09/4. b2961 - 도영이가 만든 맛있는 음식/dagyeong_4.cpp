//4
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int S[11];
int B[11];
int min_taste = INT_MAX;

void BFS(int n, int sour, int bitter) {
    if (n > N) {
        if (!bitter) return;
        min_taste = min(abs(sour - bitter), min_taste);
        return;
    }

    BFS(n + 1, sour * S[n], bitter + B[n]);
    BFS(n + 1, sour, bitter);
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    (void)freopen("b2961.txt", "r", stdin);

    cin >> N;
    for (int i = 1; i <= N; ++i) {
        cin >> S[i] >> B[i];
    }

    BFS(1, 1, 0);
    
    cout << min_taste;
    return 0;
}

#endif
