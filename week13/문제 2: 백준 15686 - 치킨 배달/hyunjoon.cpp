#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <climits>

using namespace std;

struct _location_t {
	int r, c;
}typedef location_t;

vector<location_t> home;					//가정집 좌표
vector<location_t> our_future;			//치킨집 좌표
int sel[13];							//치킨 거리 저장용

int ans = INT_MAX;

int N,M;
int map[51][51];

void inputdata() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				home.push_back({ i,j });
			}
			if (map[i][j] == 2) {
				our_future.push_back({ i,j });
			}
		}
	}
}

void printdata(){
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << map[i][j];
		}
		cout << "\n";
	}
	cout << "\n";
}

int cal_dist(location_t a, location_t b) {
	int dist = abs(a.r - b.r) + abs(a.c - b.c);
	return dist;
}

int sum_dist() {
	int tot = 0;
	for (int i = 0; i < home.size(); i++) {
		int min_dist = INT_MAX;
		for (int j = 0; j < our_future.size(); j++) {
			if (sel[j] == 1) {
				min_dist = min(min_dist, cal_dist(our_future[j], home[i]));
			}
		}
		tot += min_dist;
	}
	return tot;
}


void dfs(int idx, int L) {
	if (L >= M) {
		ans = min(ans, sum_dist());
		return;
	}
	if (idx >= our_future.size()) return;

	sel[idx] = 1;
	dfs(idx + 1, L + 1);

	sel[idx] = 0;
	dfs(idx + 1, L);
}



int main(void) {
	(void)freopen("prob2.txt", "r", stdin);
	inputdata();
	dfs(0, 0);
	cout << ans;
	return 0;
}


#endif
