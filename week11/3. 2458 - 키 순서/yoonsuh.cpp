#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> taller(N + 1);   // i보다 키 큰 
    vector<vector<int>> shorter(N + 1);  // i보다 키 작은

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b; // a < b
        taller[a].push_back(b);  // a보다 큰 사람
        shorter[b].push_back(a); // b보다 작은 사람
    }

    int answer = 0;

    for (int i = 1; i <= N; i++) {
        vector<int> visited(N + 1, 0);
        queue<int> q;

        // i보다 큰 사람 
        for (int next_person : taller[i]) {
            q.push(next_person);
            visited[next_person] = 1;
        }
        while (!q.empty()) {
            int current_person = q.front();
            q.pop();
            for (int next_person : taller[current_person]) {
                if (!visited[next_person]) {
                    visited[next_person] = 1;
                    q.push(next_person);
                }
            }
        }

        // i보다 작은 사람
        for (int next_person : shorter[i]) {
            q.push(next_person);
            visited[next_person] = 1;
        }
        while (!q.empty()) {
            int current_person = q.front();
            q.pop();
            for (int next_person : shorter[current_person]) {
                if (!visited[next_person]) {
                    visited[next_person] = 1;
                    q.push(next_person);
                }
            }
        }

        int count = 0;
        for (int j = 1; j <= N; j++) {
            if (visited[j]) count++;
        }

        if (count == N - 1) answer++;
    }

    cout << answer;
    return 0;
}
