#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX (200000)

int N, C;
vector<int> houses(MAX);

void inputData(void) {
    cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        cin >> houses[i];
    }
}

int binarySearch(void) {
    int low = 1;
    int high = houses[N-1] - houses[0];
    int rtn = 0;
    
    while (low <= high) {
        int mid = (low + high) / 2;
        int last = houses[0];
        int cnt = 1;

        for (int i = 1; i < N; i++) {
            if (houses[i] - last >= mid) {
                cnt++;
                last = houses[i];
            }
        }

        if (cnt >= C) {
            rtn = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return rtn;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b2110.txt", "r", stdin);
    inputData();
    
    sort(houses.begin(), houses.begin() + N);

    cout << binarySearch();
    return 0;
}
#endif
