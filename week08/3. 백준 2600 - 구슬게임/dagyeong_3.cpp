//오답
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
enum { A = 1, B = 2 };

int b1, b2, b3;
vector<vector<int>> k(6, vector<int>(3));
vector<vector<int>> DP;

void inputData(void) {
    cin >> b1 >> b2 >> b3;
    for (int i = 1; i <= 5; ++i) {
            cin >> k[i][1] >> k[i][2];
    }
}

void printData(void) {
    for (int i = 1; i <= 5; ++i) {
        cout << k[i][1] << ' ' << k[i][2] << '\n';
    }
    cout << endl;
}

int main(void) {
    (void)freopen("j1749.txt", "r", stdin);
    inputData();
    printData();

    DP.resize(531, vector<int>(531));

    for (int i = 31; i <= 530; ++i) {
        for (int j = 31; j <= 530; ++j) {
            if ((DP[i - b1][j] == A) || (DP[i - b2][j] == A) || (DP[i - b3][j] == A)
                || (DP[i][j - b1] == A) || (DP[i][j - b2] == A) || (DP[i][j - b3] == A)) {
                DP[i][j] = B;
            }
            else { DP[i][j] = A; }
        }
    }
    /* print DP */
    for (int i = 31; i <= 60; ++i) {
        for (int j = 31; j <= 60; ++j) {
            cout << DP[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;


    for (int i = 1; i <= 5; ++i) {
        if (DP[30 + k[i][1]][30 + k[i][2]] == A) {
            cout << 'B' << endl;
        }
        else { cout << 'A' << endl; }
    }
    return 0;
}

#endif
