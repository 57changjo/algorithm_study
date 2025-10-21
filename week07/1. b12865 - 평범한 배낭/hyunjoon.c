#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))

#define MAX_N (100+2)
#define MAX_W (100000+2)

int temp[MAX_N][MAX_W];
int N;
int K;

void inputdata() {
	(void)scanf("%d %d", &N, &K);
	for (int i = 1; i <= N; i++) {
		(void)scanf("%d %d", &obj[i].weight, &obj[i].value);
	}
}

void printdata() {
	printf("%d %d\n", N, K);
	for (int i = 1; i <= N; i++) {
		printf("%d %d\n", obj[i].weight, obj[i].value);
	}
	printf("\n");
}

void solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= K; j++) {
			if (j < obj[i].weight) {				//가방 크기보다 크면 안넣기
				temp[i][j] = temp[i - 1][j];
			}
			else {
				if (temp[i - 1][j] > temp[i - 1][j-obj[i].weight] + obj[i].value) {
					temp[i][j] = temp[i - 1][j];
				}
				else { temp[i][j] = temp[i - 1][j-obj[i].weight] + obj[i].value; }  //가방 무게 3 남았을 때, obj 1 넣는게 나아 2 넣는게 나아? 를 물어보는 loop문
			}
		}
	}
}

int main() {
	(void)freopen("prob1.txt", "r", stdin);
	inputdata();
	solve();
	printf("%d", temp[N][K]);
	return 0;
}


#endif
