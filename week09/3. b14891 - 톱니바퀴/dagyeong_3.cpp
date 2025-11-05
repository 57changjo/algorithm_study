#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int K;
vector<vector<int>> Gear(5, vector<int>(8));
vector<vector<int>> rot_list(101, vector<int>(2));

void inputData(void) {
    string s = "";
    for (int i = 1; i <= 4; ++i) {
        cin >> s;
        for (int j = 0; j < 8; ++j) {
            if (s[j] == '0') Gear[i][j] = 0; // N극
            else Gear[i][j] = 1; // S극
        }
    }
    cin >> K;
    for (int i = 1; i <= K; ++i) {
        cin >> rot_list[i][0] >> rot_list[i][1]; // 톱니번호, 방향  
    }

}
void printData(void) {
    for (int i = 1; i <= 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            cout << Gear[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << endl;
}

void rotation(int num, int dir) {
    if (dir < 0) { // 반시계
        rotate(Gear[num].begin(), Gear[num].begin() + 1, Gear[num].end());
    }
    else { // 시계
        rotate(Gear[num].begin(), Gear[num].begin() + 7, Gear[num].end());
    }
}

void solve(int i) {
    bool state[4] = { 0 };
    int num = rot_list[i][0];
    int dir = rot_list[i][1];
    //cout << num << ' ' << dir << endl;

    for (int i = 1; i <= 3; ++i) {
        state[i] = (Gear[i][2] ^ Gear[i + 1][6]); // True: 다른 극 회전
        //cout << state[i] << ' ';
    }

    if (num == 1) {
        if (state[1]) {
            rotation(2, -dir);
            if (state[2]) {
                rotation(3, dir);
                if (state[3]) {
                    rotation(4, -dir);
                }
            }
        }
        rotation(1, dir);
        return;
    }
    else if (num == 2) {
        if (state[1]) {
            rotation(1, -dir);
        }
        if (state[2]) {
            rotation(3, -dir);
            if (state[3]) {
                rotation(4, dir);
            }
        }
        rotation(2, dir);
        return;
    }
    else if (num == 3) {
        if (state[3]) {
            rotation(4, -dir);
        }
        if (state[2]) {
            rotation(2, -dir);
            if (state[1]) {
                rotation(1, dir);
            }
        }
        rotation(3, dir);
        return;
    }
    else { // num == 4
        if (state[3]) {
            rotation(3, -dir);
            if (state[2]) {
                rotation(2, dir);
                if (state[1]) {
                    rotation(1, -dir);
                }
            }
        }
        rotation(4, dir);
        return;
    }
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    //(void)freopen("b14891.txt", "r", stdin);
    inputData();
    //printData();

    for (int i = 1; i <= K; ++i) {
        solve(i);
        //cout << '\n';
        //printData();
        // rot_list[i][0]번째 톱니를 rot_list[i][1]방향으로 한칸 돌렸을때,
        // 다른 톱니들의 배열 상태 Gear[][]를 변경해주는 함수
    }
    
    cout << Gear[1][0] + 2*Gear[2][0] + 4*Gear[3][0] + 8*Gear[4][0] << endl;
    return 0;
}

#endif
