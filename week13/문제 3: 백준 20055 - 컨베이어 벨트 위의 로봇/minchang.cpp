
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int N, K;
deque<int> belt;
deque<bool> robots;    // 로봇 위치

void dataInput(void) {
    cin >> N >> K;
    for (int i = 0; i < 2 * N; i++) {
        int temp;
        cin >> temp;
        belt.push_back(temp);
    }
    // 로봇은 처음에 아무도 없음. 윗면만 관리
    robots.assign(N, false);
}

void rotateBelt(void) {
    belt.push_front(belt.back());
    belt.pop_back();

    // 벨트가 돌면 로봇도 같이 돔.
    robots.push_front(false); // 이전의 2N위치엔 로봇이 없음
    robots.pop_back();        // 로봇 떨구기

    // 회전 직후 내리는 위치에 로봇이 있다면 내리기
    if (robots[N - 1]) {
        robots[N - 1] = false;
    }
}

void moveRobots(void) {
    // N-1에 있던 애는 이미 내렸고
    // 먼저 올라간 로봇부터 움직여야함
    // N-2부터 0까지 탐색
    for (int i = N - 2; i >= 0; i--) {
        // 현재 칸에 로봇이 있고, 다음 칸에 로봇이 없고, 다음 칸 내구도가 1 이상이면
        if (robots[i] && !robots[i + 1] && (belt[i + 1] > 0)) {
            robots[i] = false;
            robots[i + 1] = true;
            belt[i + 1]--; // 내구도 감소

            // 이동 직후 내리는 위치가 내리는 위치면 내리기
            if (i + 1 == N - 1) {
                robots[N - 1] = false;
            }
        }
    }
}

void putRobot(void) {
    // 올리는 위치가 안 깨졌으면
    if (belt[0] > 0) {
        robots[0] = true;
        belt[0]--;
    }
}

bool isFinished(void) {
    int zeroCount = 0;
    for (int durability : belt) {
        if (durability == 0) {
            zeroCount++;
        }
    }
    return zeroCount >= K;
}

void solve(void) {
    int step = 0;

    while (true) {
        step++;

        // 벨트 회전
        rotateBelt();

        // 로봇 이동
        moveRobots();

        // 로봇 올리기
        putRobot();

        // 종료조건 검사
        if (isFinished()) {
            break;
        }
    }

    cout << step;
}

int main(void) {
    //(void)freopen("b20055.txt", "r", stdin);

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    dataInput();
    solve();

    return 0;
}
