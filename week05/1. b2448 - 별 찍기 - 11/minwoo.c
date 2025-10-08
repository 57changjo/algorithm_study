// ** GPT의 도움 조금 받아 푼 문제**

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 5000

char star_location[SIZE][SIZE * 2];

void triangle(int n, int y, int x) {

	// base case
	if (n == 3) {
		// 입력 n 높이 만큼
		for (int i = 0; i < n; i++) {
			// 별 5개 출력 고정
			for (int j = 0; j < 5; j++) {
				//	첫번째 라인에서 3번째 별 넣기
				if (i == 0 && j == 2) {
					star_location[y + i][x + (j - 2)] = '*';
				}
				//	두번째 라인에서 2번째, 4번째 별 넣기
				else if (i == 1 && (j == 1 || j == 3)) {
					star_location[y + i][x + (j - 2)] = '*';
				}
				//	세번째 라인에서 5개 모두 넣기
				else if (i == 2) {
					for (int k = 0; k < 5; k++) {
						star_location[y + 2][x + (k - 2)] = '*';
					}
				}
			}
		}
	}

	else {
		// n 을 반으로 나눠서 상위 하위에 위치하는 세모들 그리기
		int mid = n / 2;
		triangle(mid, y, x);
		triangle(mid, y + mid, x - mid);
		triangle(mid, y + mid, x + mid);
	}
}

#if 1
int main(void) {

	// 모든 좌표 공백으로 초기화
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE * 2; j++) {
			star_location[i][j] = ' ';
		}
	}

	int input;
	(void)scanf("%d", &input);

	// 가운데 index 찾기 (input - 1)
	triangle(input, 0, input - 1);

	for (int i = 0; i < input; i++) {
		// 세모 가로폭
		for (int j = 0; j < (input * 2) - 1; j++) {
			printf("%c", star_location[i][j]);
		}
		printf("\n");
	}
	return 0;
}
#endif
