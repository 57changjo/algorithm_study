#if 01
#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin >> T;
	int A = 300, B = 60, C = 10;

	int cntA = T / A;
	T %= A;
	int cntB = T / B;
	T %= B;
	int cntC = T / C;
	T %= C;
	if (T != 0) {
		cout << -1 << "\n";
	}
	else {
		cout << cntA << " " << cntB << " " << cntC << "\n";
	}

}
#endif
