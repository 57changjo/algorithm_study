#if 01
#include <iostream>
#include <vector>
using namespace std;

long long A, B;
vector<long long> primes;

void findPrimes(long long n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (long long i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }

    for (long long i = 2; i <= n; i++)
        if (isPrime[i])
            primes.push_back(i);
}

int solve() {
    int ans = 0;
    long long limit = 1;
    while (limit * limit <= B) limit++;
    limit--;

    findPrimes(limit);

    for (long long p : primes) {
        long long val = p * p;  // p^2부터 시작
        while (val <= B) {
            if (val >= A) ans++;
            if (val > B / p) break; // overflow 방지
            val *= p;
        }
    }
	return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> A >> B;

    int ans = solve();

    cout << ans;
    return 0;
}
#endif
