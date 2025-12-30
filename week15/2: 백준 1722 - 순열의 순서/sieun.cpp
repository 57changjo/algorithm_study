#if 01
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, n;
long long k, cnt;
vector <long long> kseq, fac;
vector <bool> visited;


void inputData() {
	cin >> N;
	cin >> n;
	kseq.assign(N + 1, 0);
	fac.assign(N + 1, 1);
	visited.assign(N + 1, false);
}

void solve1() {
	cin >> k;

	for (int i = 1; i <= N; i++) {
		cnt = 1;
		for (int j = 1; j <= N; j++) {
			// 이미 사용한 숫자는 사용할 수 없음
			if (visited[j])
				continue; 
			// 주어진 K에 따라 각 자리에 들어갈 수 있는 수 찾기
			if (k <= cnt * fac[N - i]) { 
				k -= ((cnt - 1) * fac[N - i]);
				kseq[i] = j;
				visited[j] = true;
				break;
			}
			cnt++;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << kseq[i] << " ";
	}
}

void solve2() {
	k = 1;

	for (int i = 1; i <= N; i++) {
		cin >> kseq[i];
		cnt = 0;

		for (int j = 1; j < kseq[i]; j++) {
			if (visited[j] == false) {
				cnt++; // 미사용 숫자 개수만큼 카운트
			}
		}

		k += cnt * fac[N - i]; // 자리수 개수에 따라 순서 더해주기
		visited[kseq[i]] = true;
	}
	cout << k << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	inputData();

	// 각 자릿수에서 만들 수 있는 경우의 수 - fac
	for (int i = 1; i <= N; i++) {
		fac[i] = fac[i - 1] * i;
	}

	if (n == 1)
		solve1();
	else if (n == 2)
		solve2();

	return 0;
}
#endif
