#include <iostream>
#include <string>
using namespace std;

static const long long MOD = 1000000007; //long long으로 오류 감소

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    long long ans = 0; 
    long long power = 1; // 2^0

    for (char c : s) {
        if (c == 'O') { // 실제 문자열이 아니라 O를 만났을때 이전의 수를 기준으로 규칙으로 ans 카운트만 증가
            ans = (ans + power) % MOD; // 정답을 나타내기 위한 나누기 추가
        }
        power = (power * 2) % MOD; //O가 아닐떄 즉 X 일떄마다 power를 갱신하여 ans에 반영
    }

    cout << ans << '\n';
    return 0;
}
