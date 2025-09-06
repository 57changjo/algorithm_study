#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 01
#define MAX_COM (100+2)

int c;					// 총 com 개수
int linked;				//연결된 com 개수
int worm[MAX_COM];		
int map[MAX_COM][3];


void input_Data(int (*map)[3]) {
	(void)freopen("worm.txt", "r", stdin);
	(void)scanf("%d", &c);
	(void)scanf("%d", &linked);
	for(int i = 0; i < linked; ++i ){
		(void)scanf("%d %d", map[i], map[i] + 1);
	}
}

void print_Data() {
	for (int i = 0; i < linked; i++) {
		printf("%d %d", map[i][0], map[i][1]);
		printf("\n");
	}
}

void init_worm() {
	worm[0] = 1;
}

int worm_infect() {
	int tmp;
	int fornt, rear;
	int num = 1;

	init_worm();
	for (int i = 0; i < linked; i++) {
		for(int j = 0; j < c; j++) {
			if (worm[j] == map[i][0]) {				//현재 worm[0]
				worm[num] = map[i][1];
				++num;
			}
		}
	}
	return num;
}


int main(void) {
	input_Data(map);
	print_Data();
	printf("%d", worm_infect());
	
}

#endif