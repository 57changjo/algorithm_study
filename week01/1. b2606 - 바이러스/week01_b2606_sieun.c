#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
- ����Ǿ� ����, but 4���� üũ �ƴϱ� ������ DFS�� �����
- ����Ǿ� �ִ� �� ��� �����ұ�? arr[i][j]: i, j ����. ��, ���⼺ �瓇 (��, arr[i][j], arr[j][i] ���� ������ �����ϱ�, ���� arr[x][x]�� continue �ϴ� �������

- �Է�: ù° �ٿ��� ��ǻ���� ���� �־�����. ��ǻ���� ���� 100 ������ ���� �����̰� �� ��ǻ�Ϳ��� 1�� ���� ���ʴ�� ��ȣ�� �Ű�����. ��° �ٿ��� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ�� ���� ���� �־�����. �̾ �� ����ŭ �� �ٿ� �� �־� ��Ʈ��ũ �󿡼� ���� ����Ǿ� �ִ� ��ǻ���� ��ȣ ���� �־�����.
- ���: 1�� ��ǻ�Ͱ� �� ���̷����� �ɷ��� ��, 1�� ��ǻ�͸� ���� �� ���̷����� �ɸ��� �Ǵ� ��ǻ���� ���� ù° �ٿ� ����Ѵ�.
*/

int N, M; // ��ǻ�� ����, ���� ����
int arr[101][101]; // ���� ǥ��
int virus; // ���̷��� �� ����
int visited[101]; // �湮 �� ���
// ���ǻ� 1~100�� �ε��� ���

void inputData() {
	(void)scanf("%d", &N);
	(void)scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		int a = 0, b = 0;
		(void)scanf("%d %d", &a, &b);
		arr[a][b] = 1; arr[b][a] = 1; // ���� ǥ��
	}
}

void func(int L) {

	for (int i = 1; i <= N; i++) {
		// �湮�� ���̳�, ���� ���� �н�
		if (visited[i] == 1 || L == i) continue;
		// �� �̿ܿ� ����Ǿ� ������ �湮, ���̷��� + ����� �������� �Ѿ��
		else if (arr[L][i] == 1) {
			visited[i] = 1;
			virus++;
			//printf("visit: %d\n", i);
			func(i);
		}
	}
	return;
}

int main() {
	//(void)freopen("b2606.txt", "r", stdin);
	inputData();

	visited[1] = 1; // ù ���� �湮 ǥ��
	func(1);

	printf("%d\n", virus);

	return 0;
}
#endif