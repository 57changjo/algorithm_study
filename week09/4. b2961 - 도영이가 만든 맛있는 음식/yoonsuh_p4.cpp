#include <iostream>
#include <cmath>
using namespace std;

int N;
int S[10], B[10];
int min_diff = 1000000000;

void dfs(int idx, int sour, int bitter, bool used) {
    
    if (idx == N) {
        if (used) { 
            int diff = abs(sour - bitter);
            if (diff < min_diff) min_diff = diff;
        }
        return;
    }

    dfs(idx + 1, sour, bitter, used);

    dfs(idx + 1, sour * S[idx], bitter + B[idx], true);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> S[i] >> B[i];

    dfs(0, 1, 0, false);
    cout << min_diff << "\n";
}
