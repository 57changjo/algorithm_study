#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

#define MAX_N (1000+1)

using namespace std;

int dp[MAX_N][MAX_N];

string str1;
string str2;

int LCS(void) {
	int str1_len = str1.length();
	int str2_len = str2.length();
	

	for (int i = 0; i < str1_len; i++) {
		for (int j = 0; j < str2_len; j++) {
			int dp_i = i + 1;
			int dp_j = j + 1;
			if (str1[i] == str2[j]) {
				dp[dp_i][dp_j] = dp[dp_i - 1][dp_j - 1] + 1;
			}
			else {
				dp[dp_i - 1][dp_j] > dp[dp_i][dp_j - 1] ? dp[dp_i][dp_j] = dp[dp_i - 1][dp_j] : dp[dp_i][dp_j] = dp[dp_i][dp_j - 1];
			}
		}
	}
	return dp[str1_len][str2_len];
}

int main(void) {
	cin >> str1;
	cin >> str2;
	cout << LCS();
	return 0;
}

#endif
