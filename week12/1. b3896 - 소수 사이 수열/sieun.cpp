#if 01
/*
1. findPrime() 함수로 소수만 있는 벡터 생성 (에라토스테네스의 체)
2. isPrime() 함수로 입력된 수가 소수인지 판별
3. upperBS(), lowerBS() 함수로 k의 바로 위, 아래 소수 인덱스 탐색
4. 두 소수의 차이 출력
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> primes; // 소수만 남겨둔 벡터
int pcnt; // 소수 개수

int isPrime(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return 0;
    }
    return 1;
}

void findPrime(int num) {
    const int MAXN = num;
    vector<bool> isPrime(MAXN + 1, true);
    isPrime[0] = isPrime[1] = false;

	// 에라토스테네스의 체
    for (int i = 2; i * i <= MAXN; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) 
                isPrime[j] = false;
        }
    }

    for (int i = 2; i <= MAXN; ++i) 
        if (isPrime[i]) {
            primes.push_back(i);
            pcnt++;
        }
}

int upperBS(int left, int right, int k) {
    int ans = -1;
    while (left <= right) {                
        int mid = (left + right) / 2;
        if (primes[mid] > k) { 
            ans = mid;         
            right = mid - 1;    
        }
        else {
            left = mid + 1;   
		}
    }
    return ans;
}

int lowerBS(int left, int right, int k) {
    int ans = -1;
    while (left <= right) {                
        int mid = (left + right) / 2;
        if (primes[mid] < k) {
            ans = mid;         
            left = mid + 1;    
        }
        else {
            right = mid - 1;   
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T, k;
    cin >> T;

    findPrime(1299709);

    while (T-- > 0) {
        cin >> k;
		// k가 소수인 경우
        if (isPrime(k)) {
            cout << "0\n";
            continue;
		}
		// k가 소수가 아닌 경우, 소수 인덱스로 탐색
        int upper = upperBS(0, pcnt-1, k);
        int lower = lowerBS(0, pcnt-1, k);

    // 소수 사이 수열의 길이
		cout << primes[upper] - primes[lower] << "\n";
    }

    return 0;
}

#endif
