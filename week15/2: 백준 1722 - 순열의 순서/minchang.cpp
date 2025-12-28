#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
int problemType;
long long K;           // 1번용
vector<int> targetSeq; // 2번용
long long fact[21];    // 20! 까지 저장할 배열
bool visited[21];

void dataInput(void) {
    cin >> N >> problemType;
    
    if (problemType == 1) {
        cin >> K;
    } else {
        targetSeq.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> targetSeq[i];
        }
    }
}

void solve(void) {
    fact[0] = 1;
    for (int i = 1; i <= 20; i++) {
        fact[i] = fact[i - 1] * i;
    }

    if (problemType == 1) {
        // 순열 찾기
        vector<int> result(N);

        for (int i = 0; i < N; i++) { // 자릿수 인덱스
            for (int j = 1; j <= N; j++) { // 숫자 후보
                // 사용한 숫자 pass
                if (visited[j]) continue;

                // 현재 자리에 j 픽스하면, 나머지 뒤쪽 개수는 정해짐
                long long currentCases = fact[N - 1 - i];

                // K가 이 구간 안에 포함된다면 j가 시작 지점 숫자임
                if (K <= currentCases) {
                    result[i] = j;
                    visited[j] = true;
                    break;
                }
                else {
                    // 구간 안에 안 들어오면 다음으로 가야함
                    K -= currentCases;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            cout << result[i] << " ";
        }
        cout << "\n";

    } else {
        // 순열이 몇 번째인지
        long long ans = 1;

        for (int i = 0; i < N; i++) {
            int currentNum = targetSeq[i];
            long long smallerCnt = 0; // 작은 숫자로 시작하는 패턴용

            // 사용되지 않은 숫자의 개수
            // 이 숫자들 각각 만들 수 있었던 순열만큼 밀림
            for (int j = 1; j < currentNum; j++) {
                if (!visited[j]) {
                    smallerCnt++;
                }
            }

            // 작은 미사용 숫자 개수 x 남은 자리 팩토리얼
            ans += smallerCnt * fact[N - 1 - i];
            
            visited[currentNum] = true;
        }

        cout << ans << "\n";
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b1722.txt", "r", stdin);

    dataInput();
    solve();

    return 0;
}
