#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// 0928 minchang makes PR
/* 

예제 입력 규칙

N (원판)이 1 부터 15까지 가능함

N = 3 이면

첫번째 기둥에서 1번 원판을 세번째 기둥으로 이동
첫번째 기둥에서 2번 원판을 두번째 기둥으로 이동

세번째 기둥에서 1번 원판을 두번째 기둥으로 이동 

첫번째 기둥에서 3번 원판을 세번째 기둥으로 이동

두번째 기둥에서 1번 원판을 첫번째 기둥으로 이동
두번째 기둥에서 2번 원판을 세번째 기둥으로 이동

첫번째 기둥에서 1번 원판을 세번째 기둥으로 이동

finish

*/

int N;

void HANOI(int N, int before_pole, int after_pole, int temp_pole) {

	// 원판이 하나니깐 그냥 바로 출력 base case
	if (N == 1) {
		printf("1 : %d -> %d\n", before_pole, after_pole);
		return;
	}

	HANOI(N - 1, before_pole, temp_pole, after_pole);
	printf("%d : %d -> %d\n", N, before_pole, after_pole);
	HANOI(N - 1, temp_pole, after_pole, before_pole);
}

int main(void) {

	(void)scanf("%d", &N);
	HANOI(N, 1, 3, 2);

	return 0;
}
