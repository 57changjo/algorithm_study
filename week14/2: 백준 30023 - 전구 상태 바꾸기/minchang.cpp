#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int N;
string S;

void inputData(void) {
    cin >> N >> S;
}

// R=0, G=1, B=2
int colorToInt(char c) {
    if (c == 'R') return 0;
    if (c == 'G') return 1;
    return 2;
}

// 모든 전구를 0, 1, 2 중 하나로 바꾸는데 필요한 횟수 반환
int simulate(int targetColor) {
    // 벡터 복사
    vector<int> bulbs(N);
    for (int i = 0; i < N; i++) {
        bulbs[i] = colorToInt(S[i]);
    }

    int count = 0;

    // 앞부터 맞추기
    for (int i = 0; i <= N - 3; i++) {
        while (bulbs[i] != targetColor) {
            count++;
            for (int k = 0; k < 3; k++) {
                bulbs[i + k] = (bulbs[i + k] + 1) % 3;
            }
        }
    }

    // 앞은 다 맞췄음
    // 남은 두 전구가 색이 같은지 체크
    if (bulbs[N - 2] == targetColor && bulbs[N - 1] == targetColor) {
        return count;
    }

    return INT_MAX;
}

void solve(void) {
    int ans = INT_MAX;

    for (int color = 0; color < 3; color++) {
        int result = simulate(color);
        ans = min(ans, result);
    }

    if (ans == INT_MAX) {
        cout << -1;
    }
    else cout << ans;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // (void)freopen("b30023.txt", "r", stdin);
    
    inputData();
    solve();

    return 0;
}
