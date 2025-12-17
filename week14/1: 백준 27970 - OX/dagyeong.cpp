// 오답
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

#define Div (1000000007)

string letters;
long long num;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b27970.txt", "r", stdin);
    cin >> letters;

    for (int i = 0; i < letters.size(); i++) {
        if (letters[i] == 'O') {
            num += (1LL << i);
            num %= Div;
        }
    }
    cout << num % Div;

    return 0;
}
#endif
