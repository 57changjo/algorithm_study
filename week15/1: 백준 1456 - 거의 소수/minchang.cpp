#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

long long A, B;
long long MAX_SQRT = 10000001; // root of 10^14
vector<bool> isPrime(MAX_SQRT, true);
vector<long long> primes;

void dataInput(void) {
    cin >> A >> B;
}

void solve(void) {
    // 에라어쩌고저쩌고 체
    isPrime[0] = false;
    isPrime[1] = false;
    
    for (long long i = 2; i * i < MAX_SQRT; i++) {
        if (isPrime[i]) {
            for (long long j = i * i; j < MAX_SQRT; j += i) {
                isPrime[j] = false;
            }
        }
    }

    // 소수 리스트
    for (long long i = 2; i < MAX_SQRT; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    // 거의 소수 개수 세기
    long long count = 0;
    for (long long p : primes) {
        long long curr = p;
        
        // 미친 오버플로우 curr * p <= B
        // curr <= B / p 로 B 넘는지 체크
        while (curr <= B / p) {
            // 여기서는 B 안 넘는 걸 확인 했으니 p 곱해서 체크
            curr *= p;
            if (curr >= A) {
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("b1456.txt", "r", stdin);

    dataInput();
    solve();

    return 0;
}
