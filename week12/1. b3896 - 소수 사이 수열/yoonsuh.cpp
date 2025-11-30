#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAX = 1299709;  // 문제에 나온 최대값
    vector<bool> isPrime(MAX + 1, true);

    // 1은 소수가 아니니까 제외
    isPrime[0] = isPrime[1] = false;

    // 에라토스테네스의 체
    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        int k;
        cin >> k;

        if (isPrime[k]) {
            cout << 0 << '\n';
            continue;
        }

        int left = k - 1;
        int right = k + 1;

        // k보다 작은거부분 가장 가까운 소수 찾기
        while (left >= 2 && !isPrime[left])
            left--;

        // k보다 큰부분에서 가장 가까운 소수 찾기
        while (right <= MAX && !isPrime[right])
            right++;

        cout << right - left << '\n';
    }

    return 0;
}
