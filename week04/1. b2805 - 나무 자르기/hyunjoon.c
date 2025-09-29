#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE(a) (sizeof(a)/sizeof((a)[0]))


#define MAX_N 1000000
#define MAX_M 2000000
long T[MAX_N];
int N;
long M;

void inputdata(void) {
	(void)scanf("%d %ld", &N, &M);
	for (int i = 0; i < N; i++) {
		(void)scanf("%ld", T + i);
	}
}

long max_height(long* ary) {            //나무들 중 가장 높은 나무의 길이를 찾음
	long max = 0;
	for (int i = 0; i < N; i++) {
		if (max < T[i])
			max = T[i];
		else continue;
	}
	return max;
}

void printdata(void) {
	printf("%d %ld\n", N, M);
	for (int i = 0; i < N; i++) {
		printf("%ld ", T[i]);
	}
	printf("\n");
}

long long treeheight(long long mid) {        //mid(전기톱의 높이)를 통해 mid의 전기톱 높이로 잘랐을 때의 자른 나무의 총합을 구함
	long long tree = 0;
	for (int i = 0; i < N; i++) {
		if (T[i] > mid) {                        // mid보다 Tree 높이가 커야 if 내부의 식 성립 (안그러면 T[i]-mid)는 음수
			tree = tree + (T[i] - mid);            // tree 변수에 자른 나무 계속 더함
		}
	}
	return tree;
}

long long BinarySearch_Upper(long M, long long low, long long high) {
	long long mid;
	long long ret = -1;
	while (low <= high) {
		mid = (low + high) / 2;
		long long tree = treeheight(mid);
		if (tree == M) return mid;              //treeheight(mid의 높이로 잘라본 나무들의 합)가 M(가져가려는 나무의 길이)와 같으면 mid(전기톱의 높이)를 리턴
		else if (tree > M) {
			ret = mid;                            //그렇지 않을 경우 M과 제일 가까우면서 작은 숫자 리턴(M보다 하나 작은 수)
			low = mid + 1;
		}
		else {
			high = mid - 1;
		}
	}
	return ret;
}

int main(void) {
	(void)freopen("prob1.txt", "r", stdin);
	inputdata();
	long start = 0;
	printf("%lld", BinarySearch_Upper(M, start, max_height(T)));            //가장 높은 나무를 High로 정함으로써 연산량 감소
	return 0;
}
// 자료형의 범위를 long long으로 하는 것에 유의하며 10억 이상의 나무 길이까지 포함시켜 이진 탐색 하는 문제였습니다
