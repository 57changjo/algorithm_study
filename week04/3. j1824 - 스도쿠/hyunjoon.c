#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 9


int map[SIZE][SIZE];
int flag;



void inputdata(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			(void)scanf("%d", &map[i][j]);
		}
	}
}

void printdata(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			printf("%d ", map[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int check(int r, int c, int num) {
	for (int i = 0; i < 9; i++) {
		if (map[r][i] == num) {
			return 0;
		}
	}
	for (int i = 0; i < 9; i++) {
		if (map[i][c] == num) {
			return 0;
		}
	}
	int group_r= (r / 3) * 3;							//0, 1, 2 그룹 row
	int group_c = (c / 3) * 3;							//0, 1, 2 그룹 column
	for (int i = 0; i < 3; i++) {						//내가 9개중 어느 그룹인지 판단
		for (int j = 0; j < 3; j++) {
			if (map[group_r + i][group_c + j]==num) {
				return 0;

			}
		}
	}
	return 1;
}


int sudok(void) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j]==0) {
				for (int k = 1; k <= 9; k++) {
					if (check(i, j, k)) {
						map[i][j] = k;
						sudok();
						if (flag) return 0;					//flag가 없으면 == 뭔가 채워지지 않았으면
						map[i][j] = 0;						// map 다시 빈 공간으로 돌림
					}
				}
				return 0;
			}
		}
	}
	flag = 1;
	return 0;
}


int main(void) {
	//(void)freopen("prob_3.txt", "r", stdin);
	inputdata();
	sudok();
	printdata();
	return 0;
}
