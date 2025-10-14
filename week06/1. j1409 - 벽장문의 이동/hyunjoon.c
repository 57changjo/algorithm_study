#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


#define MAX 20

int ary[MAX + 1];

int N;
int OP1, OP2;
int Len;
int Min = INT_MAX;

int returnMin(int a, int b) {
	if (a > b) return b;
	else return a;
}

void inputdata(void) {
	(void)scanf("%d", &N);
	(void)scanf("%d %d", &OP1, &OP2);
	(void)scanf("%d", &Len);
	for (int i = 1; i <= Len; i++) {
		(void)scanf("%d", &ary[i]);
	}
}

void printdata(void) {
	printf("%d\n", N);
	printf("%d %d\n", OP1, OP2);
	printf("%d\n", Len);
	for (int i = 1; i <= Len; i++) {
		printf("%d", ary[i]);
	}
	printf("\n");
}

void DFS(int L, int cnt) {
	if (L == Len + 1) {
		Min = returnMin(Min, cnt);
		return;
	}

	int des = ary[L];

	int temp = OP1;

	OP1 = des;
	DFS(L + 1, cnt + abs(temp - des));
	OP1 = temp;		// level 하나 끝났을 때 초기화

	temp = OP2;
	OP2 = des;
	DFS(L + 1, cnt + abs(temp - des));	
	OP2 = temp;	// level 하나 끝났을 때 초기화
}



int main(void) {
	//(void)freopen("prob1.txt", "r", stdin);
	inputdata();
	//printdata();
	DFS(1, 0);

	printf("%d", Min);
	return 0;
}
