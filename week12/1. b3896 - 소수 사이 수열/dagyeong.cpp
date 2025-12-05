#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 1299710

int T;
vector<int> ary(MAX);

//에라토스테네스의 체
void checkPrime(void) {
    ary[0] = ary[1] = 0;
    for (int i = 2; i < MAX; ++i) ary[i] = 1;

    for (int i = 2; i * i < MAX; ++i) {
        if (ary[i]) {
            for (int j = i * i; j < MAX; j += i) {
                ary[j] = 0;
            }
        }
    }
}

int findH(int st) {
    int i = st + 1;
    for (; i < MAX; ++i) {
        if (ary[i]) break;
    }
    return i;
}

int findL(int st) {
    int i = st - 1;
    for (; i > 0; --i) {
        if (ary[i]) break;
    }
    return i;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b3896.txt", "r", stdin);
    cin >> T;

    checkPrime();

    while (T--) {
        int n = 0;
        cin >> n;

        if (ary[n]) cout << 0 << endl;
        else {
            int high = findH(n);
            int low = findL(n);
            cout << high - low << endl;
        }
    }

    return 0;
}
