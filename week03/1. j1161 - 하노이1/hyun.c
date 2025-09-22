#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

int n;

void hanoi(int n, char from, char tmp, char to) {
	if (n == 1) {
		printf("1 : %c -> %c\n", from, to);
	}
	else {
		hanoi(n - 1, from, to, tmp);
		printf("%d : %c -> %c\n", n, from, to);
		hanoi(n - 1, tmp, from, to);
	}
}
int main() {
	(void)freopen("prob3.txt", "r", stdin);
	(void)scanf("%d", &n);
	hanoi(n, '1', '2', '3');
	return 0;
}
#endif
