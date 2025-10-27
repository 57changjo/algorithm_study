#include <iostream>

/*

 Grundy 수?

구슬 총 7개, 한번에 꺼낼 수 있는 구슬의 개수 1, 3, 4

1개: A가 1개 꺼냄 -> 0개 남음 (우승 확정) -> B가 꺼내려함 -> 구슬 없음 (패배) A승
2개: A가 1개 꺼냄 -> 1개 남음 -> B가 1개 꺼냄 -> 0개 남음 -> A가 꺼내려함 -> 구슬 없음 (패배) B승
3개: A가 1개 꺼내면
    - 2개남음 -> B가 1개 꺼냄 -> 1개 남음 -> A가 다시 1개 꺼냄 -> 0개 남음 (우승 확정) -> A승

    3개 꺼내면
    - 0개 남음 (우승 확정) A승

4개: A가 1개 -> 3개 남음 -> B 3개 꺼냄 -> 0개 남음 -> A 패배
     A가 4개 -> 0개 남음 -> A 우승
     ...
     ..
     .
*/

#if 0

// CREDIT: SIEUN

int main() {

    bool DP[501][501] = { false };
    int b1, b2, b3;
    std::cin >> b1 >> b2 >> b3;

    for (int t = 0; t < 5; t++) {
        int k1, k2;
        std::cin >> k1 >> k2;

        for (int i = 0; i <= k1; i++) {
            for (int j = 0; j <= k2; j++) {
                if (i == 0 && j == 0) continue;

                bool can_win= false;

                if (i >= b1 && !DP[i - b1][j]) can_win = true;
                if (i >= b2 && !DP[i - b2][j]) can_win = true;
                if (i >= b3 && !DP[i - b3][j]) can_win = true;

                if (j >= b1 && !DP[i][j - b1]) can_win = true;
                if (j >= b2 && !DP[i][j - b2]) can_win = true;
                if (j >= b3 && !DP[i][j - b3]) can_win = true;

                DP[i][j] = can_win;
            }
        }

        std::cout << (DP[k1][k2] ? "A\n" : "B\n");
    }

    return 0;
}
#endif
