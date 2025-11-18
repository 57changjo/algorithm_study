// 오답

#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <climits>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<vector<int>> map(22, vector<int>(22));
int sr, sc;
vector<int> num_fish(10);
int baby_size = 2;
int second;

typedef struct node{
    int r;
    int c;
}node_t;
vector<node_t> Queue(20 * 20);
int front, rear;
int dr[4] = { -1, 0, +1, 0 };
int dc[4] = { 0, -1, 0, +1 };

int BFS(void) { // 물고리 한마리 먹기 -> 시간 반환
    node_t curr = { 0 };
    int visited[21][21] = { 0 };
    front = rear = 0;

    Queue[rear++] = { sr, sc };
    visited[sr][sc] = 1;

    while (front != rear) {
        curr = Queue[front++];
        int time = visited[curr.r][curr.c];
        for (int i = 0; i < 4; ++i) {
            int newR = curr.r + dr[i];
            int newC = curr.c + dc[i];
            if (newR <= 0 || newC <= 0 || newR > N || newC > N) continue;
            if (visited[newR][newC]) continue;
            if (map[newR][newC] > baby_size) continue; // 못 지나감
            else if (map[newR][newC] <= 0 || map[newR][newC] == baby_size) {
                Queue[rear++] = { newR, newC };
                visited[newR][newC] = time + 1;
            }
            else { // 0 < map[newR][newC] < baby_size => 먹음
                sr = newR;
                sc = newC;
                num_fish[map[newR][newC]]--;
                map[newR][newC] = 0;
                return time;
            }
        }
    }
    return 0;
}

int countFish(void) { // 먹을 수 있는 물고기 수 확인
    int cnt = 0;
    for (int i = 1; i < baby_size; ++i) {
        cnt += num_fish[i];
    }
    return cnt;
}

int main(void) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    (void)freopen("b16236.txt", "r", stdin);

    // inputData
    cin >> N;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> map[i][j]; // 빈칸, 아기상어, 물고기 크기(1~6)
            num_fish[map[i][j]]++; // 크기별 물고기 수 저장
            if (map[i][j] == 9) {
                sr = i;
                sc = j;
                map[i][j] = 0;
            }
        }
    }
    
    while (1) {
        int count = countFish();

        if (count <= 0) {
            second += 0;
            break;
        }
        else if (count >= baby_size) {
            for (int i = 0; i < baby_size; ++i) {
                second += BFS();
            }
            baby_size++;
        }
        else { // 1 <= count < baby_size
            while (count--) {
                second += BFS();
            }
            break;
        }
    }

    cout << second;
    return 0;
}
