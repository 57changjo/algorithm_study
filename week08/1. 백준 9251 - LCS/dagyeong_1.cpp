#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

string s1, s2;
vector<vector<int>> DP;

int main(void) {
    (void)freopen("b9251.txt", "r", stdin);
    cin >> s1 >> s2;
    s1 = '0' + s1;
    s2 = '0' + s2;
    // cout << s1 << " : " << s1.size() << '\n';
    // cout << s2 << " : " << s2.size() << '\n';

    DP.resize(s1.size(), vector<int>(s2.size()));

    for (int i = 1; i < s1.size(); ++i) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                DP[i][j] = DP[i - 1][j - 1] + 1;
            }
            else if (DP[i - 1][j] > DP[i][j - 1]) {
                DP[i][j] = DP[i - 1][j];
            }
            else {
                DP[i][j] = DP[i][j - 1];
            }
        }
    }
    /* print DP */
    /*for (int i = 1; i < s1.size(); ++i) {
        for (int j = 1; j < s2.size(); j++) {
            cout << DP[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;*/

    cout << DP[s1.size() - 1][s2.size() - 1] << endl;
    return 0;
}

#endif
