// 2
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int A, B, C, T;

int main(void) {
    cin >> T;

    if (T % 10) {
        cout << -1 << endl;
    }
    else {
        A = T / 300;
        B = (T % 300) / 60;
        C = ((T % 300) % 60) / 10;
        cout << A << ' ' << B << ' ' << C << endl;
    }
    return 0;
}

#endif
