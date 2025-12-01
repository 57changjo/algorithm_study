#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_K 1300000
using namespace std;

bool isPrime[MAX_K];
vector<int> primes;

void inputData(void) {
    fill(isPrime, isPrime + MAX_K, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < MAX_K; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX_K; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 소수 벡터에 넣기
    for (int i = 2; i < MAX_K; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }
}

int solve(void) {
    int T;
    cin >> T;

    while (T--) {
        int k;
        cin >> k;

        // k가 소수면 0
        if (isPrime[k]) {
            cout << 0 << "\n";
        }
		// k가 소수가 아니면
        else {
            // k보다 큰 첫 번째 원소 위치 탐색
            auto right_ptr = lower_bound(primes.begin(), primes.end(), k);

            int right_prime = *right_ptr;
            int left_prime = *(right_ptr - 1);

            cout << right_prime - left_prime << "\n";
        }
    }
    return 0;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // (void)freopen("b3896.txt", "r", stdin);

    inputData();
    solve();

    return 0;
}
