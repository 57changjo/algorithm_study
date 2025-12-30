#if 01
/*
유니온 파인드에 대한 공부
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, M;
int hop, a, b;
static  vector<int> parent;

// find 연산 : 루트 노드를 찾아서 리턴
// 루트 노드가 아니면 재귀적으로 부모 노드를 타고 올라감
int find(int a) {	 
    if (a == parent[a])
        return a;
    else
        return parent[a] = find(parent[a]);	 // 재귀함수
}

/*
union 연산 : 바로 연결이 아닌 루트 노드끼리 연결하여 줌
x, y가 매개변수로 들어왔을 때, x와 y의 루트노드가 같다면 같은 집합이므로 종료하고,
아니라면 y의 부모를 x로 바꿔준다.
*/
void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) {
        parent[b] = a;
    }
}

// 두 원소가 같은 집합인지 확인
bool checkSame(int a, int b) { 
    a = find(a);
    b = find(b);
    if (a == b) {
        return true;
    }
    return false;
}

void solve() {
    // 루트 노드를 자기 자신으로 초기화 하기
    for (int i = 0; i <= N; i++) { 	
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        // 입력이 여기가 좋을 것 같아
        cin >> hop >> a >> b;
        // 집합 합치기
        if (hop == 0) { 	
            unionfunc(a, b);
        }
        // 같은 집합의 원소인지 확인하기
        else {	 
            if (checkSame(a, b)) {
                cout << "YES" << "\n";
            }
            else {
                cout << "NO" << "\n";
            }
        }
    }
}

void inputData() {
    cin >> N >> M;
    parent.resize(N + 1);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    inputData();
    solve();
}

#endif
