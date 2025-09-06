#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
- 2606���� ����

�Է�: ù° �ٿ� ������ ���� N�� ������ ���� M�� �־�����. (1 �� N �� 1,000, 0 �� M �� N��(N-1)/2) ��° �ٺ��� M���� �ٿ� ������ �� ���� u�� v�� �־�����. (1 �� u, v �� N, u �� v) ���� ������ �� ���� �־�����.
���: ù° �ٿ� ���� ����� ������ ����Ѵ�.
*/
int N, M; // ���� ����, ���� ����
int arr[1001][1001]; // ���� ǥ��
int connected; // ���� ��� ����
int visited[1001]; // �湮 ���� ���
// ���ǻ� 1~1000�� �ε��� ���

void inputData() {
	(void)scanf("%d %d", &N, &M);
	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		(void)scanf("%d %d", &a, &b);
		arr[a][b] = 1; arr[b][a] = 1; // ���� ǥ��
	}
}

void func(int L) {
	// ���� ���� �ȿ��� �湮
	for (int i = 1; i <= N; i++) {
		// �湮�� ���̳�, ���� ���� �н�
		if (visited[i] == 1 || L == i) continue;
		// �� �̿ܿ� ����Ǿ� ������ �湮, ����� �������� �Ѿ��
		else if (arr[L][i] == 1) {
			visited[i] = 1;
			// printf("visit: %d\n", i);
			func(i);
		}
	}
	return;
}

int main() {
	// (void)freopen("b11724.txt", "r", stdin);
	inputData();

	for (int i = 1; i <= N; i++) {
		if (!visited[i]) { // �湮���� ���� ������ ���� - BFS �ȿ��� visited Ȯ���ϱ� �Ⱦ �̷��� �ٲ�
			connected++;
			func(i); // i���� DFS ���� - �� 1���� ���� ����
		}
	}

	printf("%d\n", connected);

	return 0;
}
#endif