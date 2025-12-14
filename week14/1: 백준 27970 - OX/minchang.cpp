#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string S;
long long N;
int MOD = 1000000007;

void inputData(void) {
    cin >> S;
    N = S.length();
}

void solve(void) {
    long long answer = 0;
    long long powerOfTwo = 1;

    for (int i = 0; i < N; i++) {
        if (S[i] == 'O') {
            answer = (answer + powerOfTwo) % MOD;
        }
        powerOfTwo = (powerOfTwo * 2) % MOD;
    }

    cout << answer << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // (void)freopen("b27970.txt", "r", stdin);

    inputData();
    solve();

    return 0;
}
