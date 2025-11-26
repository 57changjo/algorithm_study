#if 1

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N (500+1)

using namespace std;

struct _tree {
	vector<_tree *> high;
	vector<_tree *> low;
}typedef tree_t;

tree_t tree[MAX_N];		//index 자체가 학생의 number

int N;
int M;
int cnt_upper, cnt_lower;
bool visited[MAX_N];

void inputdata() {
	int lower = 0;
	int higher = 0;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> lower >> higher;
		tree[lower].high.push_back(tree + higher);		//더 낮은 학생 node의 higher 부분을 그 주소로 변경
		tree[higher].low.push_back(tree + lower);			//더 높은 학생 node의 lower 부분을 그 주소로 변경
	}
}

void uppercnt(tree_t* node) { //tree는 특정 학생node의 high가 들어옴
	for(int i = 0; i < node->high.size(); i++){			//upper에는 주소값이 담겨있음
		/*cout << "uppercount i : " << i <<'\n';*/
		tree_t* upper = node->high[i];
		int next = upper - tree;
		if (!visited[next]) {
			visited[next] = true;
			++cnt_upper;
			uppercnt(upper);
		}
	}
	return;
}

void lowercnt(tree_t* node) { //tree는 특정 학생node의 low가 들어옴
	for (int i = 0; i < node->low.size(); i++) {			//lower에는 주소값이 담겨있음
		/*cout << "lowercount i : " << i << '\n';*/
		tree_t* lower = node->low[i];
		int next = lower - tree;
		if (!visited[next]) {
			visited[next] = true;
			++cnt_lower;
			lowercnt(lower);
		}
	}
	return;
}


int solve() {
	tree_t* upper;
	tree_t* lower;
	int ans = 0;
	//cout << "sucess\n";
	// 1~N까지 내 위, 아래를 다 세고, 다 셌을 때 N-1만큼 count가 올라갔으면 내 순서를 알고있는 것
	for (int i = 1; i <= N; i++) {
		fill(visited, visited + N + 1, false);
		cnt_upper = cnt_lower = 0;
		visited[i] = true;
		uppercnt(&tree[i]);
		lowercnt(&tree[i]);
		/*cout << cnt_lower + cnt_upper << "  :cnt \n";*/
		if (cnt_upper + cnt_lower == N - 1) ++ans;
	}
	return ans;
}

int main(void) {
	(void)freopen("prob3.txt", "r", stdin);
	inputdata();
	cout << solve();

	return 0;
}


#endif
