// b14891 - 톱니바퀴
#if 01
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> topni(4, vector<int>(8));

void rClock(vector<int>& gear) {
    int temp = gear.back();
    for (int i = 7; i > 0; i--) gear[i] = gear[i - 1];
    gear[0] = temp;
}

void rCounterClock(vector<int>& gear) {
    int temp = gear.front();
    for (int i = 0; i < 7; i++) gear[i] = gear[i + 1];
    gear[7] = temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for (int i = 0; i < 4; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++) {
            topni[i][j] = s[j] - '0';
        }
    }

    int N = 0;
    cin >> N;
    while (N-- > 0) {
        int tNum, dir;
        cin >> tNum >> dir;
        tNum--;

        vector<int> rDir(4, 0);
        rDir[tNum] = dir;

        // 왼쪽 방향 전파
        for (int i = tNum - 1; i >= 0; i--) {
            if (topni[i][2] != topni[i + 1][6])
                rDir[i] = -rDir[i + 1];
            else
                break;
        }

        // 오른쪽 방향 전파
        for (int i = tNum + 1; i < 4; i++) {
            if (topni[i - 1][2] != topni[i][6])
                rDir[i] = -rDir[i - 1];
            else
                break;
        }

        // 회전 적용
        for (int i = 0; i < 4; i++) {
            if (rDir[i] == 1) rClock(topni[i]);
            else if (rDir[i] == -1) rCounterClock(topni[i]);
        }
    }
    // 점수 계산
    int score = 0;
    for (int i = 0; i < 4; i++) {
        score += topni[i][0] * (1 << i);
    }

    cout << score;

    return 0;
}

#endif
