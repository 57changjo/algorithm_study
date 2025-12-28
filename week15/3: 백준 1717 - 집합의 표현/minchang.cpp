#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> parent;

void dataInput(void) {
    cin >> N >> M;
    
    parent.resize(N + 1);
    
    // 처음에는 모든 원소가 각각 독립된 집합임 : 자기 자신을 부모
    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }
}

int findRoot(int x) {
    // 자기 자신이 부모라면 루트 노드임
    if (parent[x] == x) return x;

    // 재귀적으로 부모를 찾으면서 찾은 루트로 갱신
    return parent[x] = findRoot(parent[x]);
}

void mergeSets(int a, int b) {
    // 각 원소의 루트를 찾음
    int rootA = findRoot(a);
    int rootB = findRoot(b);

    // 서로 다른 집합이면 합침
    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}

void solve(void) {
    for (int i = 0; i < M; i++) {
        int cmd, a, b;
        cin >> cmd >> a >> b;

        if (cmd == 0) {
            mergeSets(a, b);
        } else {
            if (findRoot(a) == findRoot(b)) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //(void)freopen("b1717.txt", "r", stdin);

    dataInput();
    solve();

    return 0;
}
