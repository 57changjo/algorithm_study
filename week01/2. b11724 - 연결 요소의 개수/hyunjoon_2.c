#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#if 00
#define MAX_N (1000+2)

int rail[MAX_N][MAX_N];
int N, M;

void input_Data(int (*map)[3]) {
	(void)freopen("rail.txt", "r", stdin);
	(void)scanf("%d", &N, &M);
	for (int i = 0; i < M; ++i) {
		(void)scanf("%d %d", rail[i], map[i] + 1);
	}
}


void DFS(int V) {
	visited[V] = 1;
	for (int i = 1; i <= N; i++)
		if (coord[V][i] && !visited[i])
			DFS(i);
}

void print_Data() {
	for (int i = 0; i < m; i++) {
		printf("%d %d", map[i][0], map[i][1]);
		printf("\n");
	}
}

rail_t read[MAX_N];
void init_rail() {
	for (int i = 0; i < m; i++) {
		read[i] = (rail_t){ map[i][0], map[i][1] };
	}
}



int worm_infect() {
	int tmp = 1;
	int num = 2;
	s[0][0] = (rail_t){ map[0][0], map[0][1] };
	for (int i = 0; i < n; i++) {
		int k = 0;
		for (int j = 0; j < m; j++) {
			if (s[i][j].start == read[k].start || s[i][j].end == read[k].start || 
				s[i][j].start == read[k].end || s[i][j].end == read[k].end) {				//ÇöÀç worm[0]
				s[i][num] = read[k];
				++k;
				++num;
			}
			continue;
		}
		if()
	}
	return tmp;
}


int main(void) {
	input_Data(map);
	print_Data();
	printf("%d", worm_infect());

}

#endif