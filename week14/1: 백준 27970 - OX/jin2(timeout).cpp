#include <iostream>
#include <vector>
#include <string>

//애매하기 하지만 일단 한번 의도대로 하고 안되면 시간 초과 규칙으로 풀어보자
using namespace std;

static const long long MOD = 1000000007; //출력값에 10^9 +7 나타내기 위한 것

vector<char> arr; // 요소를 char + 동적으로 늘리기 위한 백터 설정
int answer = 0;

/* 입력 함수 */
void input() {
    string s;
    cin >> s;

    for (char c : s) { //실제 받은 문자열을 짤라서 그만큼 요소로 넣기
        arr.push_back(c);
    }
}

/* 문제 해결 함수 */
void solve() {
    int n = arr.size();

    // 맨 앞 조건: X 하나만 있는 경우
    if (n == 1 && arr[0] == 'X') {
        answer = 0;
        return;
    }

    while (true) {
        int idx = -1;

        // 가장 왼쪽 O 찾기
        for (int i = 0; i < n; i++) {
            if (arr[i] == 'O') {
                idx = i;
                break;
            }
        }

        // O가 없다면 종료
        if (idx == -1) break;

        // 해당 O를 X로 변경
        arr[idx] = 'X';

        // 그보다 왼쪽 X → O
        for (int i = 0; i < idx; i++) {
            if (arr[i] == 'X') {
                arr[i] = 'O';
            }
        }

        answer = (answer + 1) % MOD;
    }
}

/* 출력 함수 */
void output() {
    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    solve();
    output();

    return 0;
}
// 시간 오버
