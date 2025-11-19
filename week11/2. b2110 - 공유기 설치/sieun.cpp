#if 01
/*
1. 집 정렬
2. D의 최솟값 1, 최댓값 jip[N-1]-jip[0] 을 left, right로 두어,
D의 이분 탐색
3. 이분 탐색 중 isPossible() 함수를 통해 설치 가능한지 확인
4. 이분 탐색 중 ans라는 변수에다가 일단 가능한 값을 저장
5. 이분 탐색 마지막에서 가능한 값의 최댓값 반환
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> jip;


bool isPossible(int D) {
    int cnt = 1; // 첫 번째 집부터 시작
    int curr = jip[0];
    for (int i = 1; i < N; i++) {
        if (jip[i] - curr >= D) {
            cnt++;
            curr = jip[i];
        }
    }

    return cnt >= C;
}

int binarySearch(int left, int right) {
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isPossible(mid)) { // mid 조건으로 설치/배치/충족 가능한지
            ans = mid;         // mid는 가능한 값 → 기록
            left = mid + 1;    // 더 큰 값도 가능한지 오른쪽 탐색
        }
        else {
            right = mid - 1;   // mid는 불가능 → 줄여야 함
        }
    }

    return ans; // 가능한 값 중 최댓값을 반환
}

void inputData() {
    cin >> N >> C;
    jip.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> jip[i];
    }
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

    inputData();
    sort(jip.begin(), jip.end());
    cout << binarySearch(1, jip[N-1]-jip[0]);
}

#endif
