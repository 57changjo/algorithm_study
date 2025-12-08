# 📆 Week 13 스터디 정리

## 📌 주제
- 이번 주 주제: (예: 배열 & 포인터 기초, DFS/BFS, DP 기초 등)
- 출제자: 조민창

---

## 📂 다룬 문제
1. [문제 1: 백준 16918 - 봄버맨](https://www.acmicpc.net/problem/16918)
2. [문제 2: 백준 15686 - 치킨 배달](https://www.acmicpc.net/problem/15686)
3. [문제 3: 백준 20055 - 컨베이어 벨트 위의 로봇](https://www.acmicpc.net/problem/20055)

---

## 📊 발표 담당
- 문제 1: 박민우
- 문제 2: 조윤서
- 문제 3: 최현준

---

## 📝 리뷰 요약 (홍시은)
### 문제 1: (문제명)
- 풀이 접근: 시뮬레이션, 패턴을 찾으면 된다.
- 주요 코드/아이디어: 
t = 0 제일 처음에 일부 칸에 폭탄을 설치한다
t = 1 아무것도 안 함 (초기 상태 동일)
t = 2 폭탄이 설치되어 있지 않은 칸에 폭탄을 설치함
t = 3 제일 처음에 설치된 폭탄이 모두 폭발함
t = 4 또 전체 폭탄 설치
t = 5 t = 2 일 때 설치한 폭탄 폭발
...
짝수 초 모두 폭탄 설치되었을 때
홀수 초 %4 == 3일 때와 %4 == 1일 때의 경우로 나눠진다. (폭탄 설치 후 3초 후 폭발하므로)
```
char map_start[SIZE][SIZE];
char map_after1[SIZE][SIZE];
char map_after2[SIZE][SIZE];
```
을 세 개를 써서 한 번 터졌을 때, 두 번 터졌을 때를 저장한다.
민우님 풀이에서 조금 보완을 하자면
```
for (int k = 0; k < 4; k++) {
int ny = i + dy[k];
int nx = j + dx[k];
}
```
와 같이 주변을 접근하는 것이 좋겠다.

c++에서는 함수 파라미터에 배열을 넣으면 메모리를 전체 복사해온다. 만약에 맵이 너무 커지면 시간이 많이 소요된다.
따라서 다음과 같이 사용하길 권장한다. 그러면 연산에 필요한 부분이 있으면 그 부분만 가져오기 때문에 효율적이다. (포인터처럼 쓰는 느낌)
```
vector<string> explode(vector<string>& currentGrid)
```

+ 재귀 풀이
bomb_org, bomb_cp를 사용해서 터트리고 업데이트하는 걸 반복한다.
enum에서 한 글자라서 char도 사용가능했다.

- 리뷰 포인트:
앞으로도 함수화를 습관화하자
시뮬레이션 문제에서 패턴을 잘 찾아보자


### 문제 2: (문제명)
- 풀이 접근: DFS를 곁들인 시뮬레이션
- 주요 코드/아이디어:
맵에다가 집이랑 치킨집을 박아버리면 머리가 터져버린다. (못 푼다)
주머니에서 꺼내서 쓰는 방식으로 접근하자. (벡터)
dataInput에서 읽어올 때부터 집, 치킨집 등을 벡터에 저장한다.

DFS + 백트래킹을 통해서 selected에 모든 경우의 M개의 치킨집을 저장한다.
이때, push_back(), pop_back()을 사용하여 모든 조합을 선택할 수 있다.
```
for (int i = idx; i < chickens.size(); i++) {
        selected.push_back(chickens[i]);

        DFS(i + 1, count + 1);

        // 복구
        selected.pop_back();
    }
```
이에 따라 모든 selected 경우에 대해 거리를 계산하면서 minimum을 갱신하여 답을 찾는다.

auto라는 것을 통해 문법을 생각하지 않을 수 있다. &를 붙인 건 c를 reference로 쓰겠다는 거다.
또한 벡터를 사용해서 for문을 사용할 때 하나씩 꺼내서 쓸 수 있다.
```
for (auto& c : selected) {
            int d = getDist(h, c);
            if (d < minDist) {
                minDist = d;
            }
        }
```
+ prev_permutation 함수를 사용하여 조합 찾기 <algorithm> 헤더 파일
fill(select.begin(), select.begin() + M, true); // 앞에서부터 M개 true, 나머지(치킨집 수) false인 벡터 생성 후
select 벡터에 대해서 prev_permutation(select.begin(), select.end())를 통해서 M개의 치킨집을 고를 수 있다.
prev_permutation의 return값은 bool 타입, 기본은 true, 이전 순열이 없을 때 false를 반환

- 리뷰 포인트:
벡터를 사용한 for문 사용법
조합 구하는 방법
1. DFS
2. c++에는 combination 함수가 있다. <algorithm>
3. 비트 연산


### 문제 3: (문제명)
- 풀이 접근: 비문학 읽기 능력이 필요한 시뮬레이션
- 주요 코드/아이디어: 
1단계: 컨베이어 벨트가 로봇을 가지고 이동
2단계: 로봇 한 칸 이동
3단계: 로봇 내리기
(단, 내구도가 0이 되면 정체된다.)
를 반복하는 것을 잘 파악해야 한다.
즉, 문제에서 요구하는 동작을 잘 이해해야 한다.
```
roll();
mov_robot();
load_robot();
```
mov_robot()에서는
먼저 올라간 로봇이 먼저 내려가기 때문에 for문에서 내리는 위치인 N-1부터 줄여가는 방식으로 세워야 한다.
그리고 로봇이 내리는 위치에 도달하면 그 즉시 내리기 때문에 움직이고 바로 unload_robot();를 바로 수행한다.

+ deque를 사용해서 push.front(), pop.back()을 통해서 컨베이어 벨트를 돌릴 수 있다.
+ N-1에는 항상 로봇이 내려간 상태이다 -> for문 N-2에서 시작해도 된다.

- 리뷰 포인트:
문제를 차분하게 분석하면서 따라가자
유지보수를 하려면 함수화를 하자
---

## 📚 추가 학습/참고
- (예: 시간복잡도 개념 정리 필요 → docs/algorithm_notes.md 반영 예정)
- (예: 문자열 문제 접근 시 카운팅/정렬 두 방식 비교)

---

## ✅ 다음주 문제 출제자: 전진
- 문제 번호 및 링크:
  1. 문제 1: [백준 27970 - OX](https://www.acmicpc.net/problem/27970)
  2. 문제 2: [백준 30023 - 전구 상태 바꾸기](https://www.acmicpc.net/problem/30023)
  3. 문제 3: [백준 1245 - 농장관리](https://www.acmicpc.net/problem/1245)
