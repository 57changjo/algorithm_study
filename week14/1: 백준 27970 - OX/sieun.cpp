#if 01
/*
1. 문자열에서 가장 왼쪽에 있는 O를 찾는다.
2. 그 O를 X로 바꾼다.
3. 그 O보다 왼쪽에 있는 모든 문자를
X → O, O → X 뒤집는다.
4. 다시 O가 있으면 반복.
근데 이걸 그대로 구현하면 시간 초과
-> i번째 O는 정확히 2^i 만큼 연산을 발생시킨다.
-> 따라서 O의 개수만큼 2의 거듭제곱을 더해주면 된다.
-> 코드 구현은 허무하다
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ll = long long;
const ll MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    ll ans = 0;
    ll pow2 = 1;   // 2^0, 2^1, 2^2,  ...

    for (char c : s) {
        if (c == 'O') {
            ans = (ans + pow2) % MOD;
        }
        pow2 = (pow2 * 2) % MOD;
    }

    cout << ans << "\n";
    return 0;
}
#endif
