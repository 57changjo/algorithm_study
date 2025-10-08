// **GPT의 도움을 받아 푼 문제**

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 2000

int N;
int x;
int cid, pid;
int tree[SIZE][SIZE];
int child_node_count[SIZE];
int visited1[SIZE];
int root_dist[SIZE];
int sub_tree[SIZE];
int farthest_child[SIZE];

int Queue[SIZE];
int dist[SIZE];
int visited2[SIZE];
int front, rear;
int max_distance;

void Tree_dfs(int cur, int parent, int dist) {
	visited1[cur] = 1;
	root_dist[cur] = dist;
	sub_tree[cur] = 1;
	farthest_child[cur] = 0;

	for (int i = 0; i < child_node_count[cur]; i++) {
		int next = tree[cur][i];
		
		if (next == parent) continue;
		Tree_dfs(next, cur, dist + 1);
		sub_tree[cur] += sub_tree[next];

		if (farthest_child[next] + 1 > farthest_child[cur]) {
			farthest_child[cur] = farthest_child[next] + 1;
		}
	}
}

int Tree_bfs(int start) {

	front = 0;
	rear = 0;
	max_distance = 0;

	Queue[rear++] = start;
	dist[start] = 0;
	visited2[start] = 1;

	while (front < rear) {
		int cur = Queue[front++];

		if (dist[cur] > max_distance) {
			max_distance = dist[cur];
		}

		for (int i = 0; i < child_node_count[cur]; i++) {
			int next = tree[cur][i];
			
			if (visited2[next]) continue;

			visited2[next] = 1;
			dist[next] = dist[cur] + 1;
			Queue[rear++] = next;
		}
	}
	return max_distance;
}

int main(void) {

	(void)scanf("%d", &N);

	for (int i = 0; i < N - 1; i++) {
		(void)scanf("%d %d", &cid, &pid);
		tree[pid][child_node_count[pid]++] = cid;
		tree[cid][child_node_count[cid]++] = pid;
	}

	(void)scanf("%d", &x);

	Tree_dfs(1, -1, 0);

	printf("%d\n", root_dist[x]);
	printf("%d\n", sub_tree[x]);
	printf("%d\n", farthest_child[x]);
	printf("%d\n", Tree_bfs(x));

	return 0;
}
