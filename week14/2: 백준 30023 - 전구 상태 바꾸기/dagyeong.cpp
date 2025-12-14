#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;
enum { r = 0, g = 1, b = 2 };

int N;
vector<int> origin;

void inputData(void) {
    cin >> N;
    string s;
    cin >> s;

    for (int i = 0; i < N; i++) {
        if (s[i] == 'R') origin.push_back(r);
        else if (s[i] == 'G') origin.push_back(g);
        else origin.push_back(b);
    }
}

int solve(int base) {
    vector<int> arr = origin;
    int cnt = 0;

    for (int i = 0; i <= N - 3; i++) {
        if (arr[i] == base) continue;

        if (arr[i] == (base + 1) % 3) { // 2번 더하기
            for (int k = 0; k < 3; ++k) arr[i + k] = (arr[i + k] + 2) % 3;
            cnt += 2;
        } else {
            for (int k = 0; k < 3; ++k) arr[i + k] = (arr[i + k] + 1) % 3;
            cnt++;
        }
    }

    if (arr[N - 2] != base || arr[N - 1] != base) return -1;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b30023.txt", "r", stdin);
    inputData();

    int min_ans = -1;
    for (int i = 0; i < 3; ++i) {
        int ans = solve(i);
        if (ans == -1) continue;
        else if (min_ans == -1) min_ans = ans;
        else min_ans = min(min_ans, ans);
    }

    cout << min_ans;
    return 0;
}
