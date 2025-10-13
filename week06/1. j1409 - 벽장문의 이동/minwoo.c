#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// j1409 벽장문의 이동

// 사용할 벽장들 보관
int order[21];

// 벽장 개수
int door_cnt = 0;

// 열려있는 벽장들
int opened_door1, opened_door2;

// 사용할 벽장들 순서 길이
int order_len;

int dfs(int opened_door1, int opened_door2, int index) {

	if (index == order_len) return 0;

	// 벽장번호 3 -> 1 -> 6 -> 5
	int curr_door = order[index];

	int opened_door1_cost = abs(opened_door1 - curr_door);
	int opened_door2_cost = abs(opened_door2 - curr_door);

	int opened_door1_cost_total = opened_door1_cost + dfs(curr_door, opened_door2, index + 1);
	int opened_door2_cost_total = opened_door2_cost + dfs(opened_door1, curr_door, index + 1);

	return (opened_door1_cost_total < opened_door2_cost_total ? opened_door1_cost_total : opened_door2_cost_total);
}

int main(void) {

	(void)scanf("%d %d %d %d", &door_cnt, &opened_door1, &opened_door2, &order_len);

	for (int i = 0; i < order_len; i++) {
		(void)scanf("%d", &order[i]);
	}

	printf("%d", dfs(opened_door1, opened_door2, 0));

	return 0;
}
#endif
