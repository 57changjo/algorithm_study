// j1161 - 하노이1
// n == 3 동작
/* general 동작, think about recursion
1. Move (n-1) disc from P1 to P2
2. Move 1 disc from P1 to P3
3. Move (n-1) disc from P2 to P3
*/
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void move(int n, int from, int to) {
    printf("%d : %d -> %d\n", n, from, to);
}

// num of disc, start point, middle point, target point
void hanoi(int n, int from, int by, int to) {
    // terminate condition
    if (n == 1)
        move(n, from, to);
    else {
        hanoi(n - 1, from, to, by);
        move(n, from, to);
        hanoi(n - 1, by, from, to);
    }
}

int main() {
    int i = 0;
    // pillars
    int from = 1, by = 2, to = 3;

    scanf("%d", &i);
    hanoi(i, from, by, to);

    return 0;
}
#endif
