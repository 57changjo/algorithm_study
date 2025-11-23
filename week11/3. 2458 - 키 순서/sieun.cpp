#if 01
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> graph, reverseGraph;

int bfs(int start, const vector<vector<int>>& g) {
    vector<int> visited(N + 1, 0);
    queue<int> q;

    visited[start] = 1;
    q.push(start);

    int count = 0;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next : g[cur]) {
            if (!visited[next]) {
                visited[next] = 1;
                q.push(next);
                count++;
            }
        }
    }

    return count;
}

int solve() {
    int answer = 0;
    for (int i = 1; i <= N; i++) {
        int taller = bfs(i, graph); // i보다 큰 사람 수
        int smaller = bfs(i, reverseGraph); // i보다 작은 사람 수

        if (taller + smaller == N - 1)
            answer++;
    }

    return answer;
}

void inputData() {
    cin >> N >> M;
    // 1~N 유지하려고 N+1
    graph.assign(N + 1, vector<int>());
    reverseGraph.assign(N + 1, vector<int>());

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        // a < b;
        graph[a].push_back(b); // a보다 큰
        reverseGraph[b].push_back(a); // b보다 작은
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    inputData();
    cout << solve();

    return 0;
}

#endif
