# 📆 Week 2 스터디 정리

## 📌 주제
- 이번 주 주제: BFS
- 출제자: 홍시은

---

## 📂 다룬 문제
1. [백준 1012 - 유기농 배추](https://www.acmicpc.net/problem/1012)
2. [백준 2178 - 미로 탐색](https://www.acmicpc.net/problem/2178)
3. [백준 12851 - 숨바꼭질 2](https://www.acmicpc.net/problem/12851)

---

## 📊 발표 담당
- 문제 1: 조민창
- 문제 2: 김다경
- 문제 3: 박민우

---

## 📝 리뷰 요약
- 정리담당: 조윤서
### 문제 1: 유기농 배추
- 풀이 접근:
  그래프 탐색 문제 (BFS, DFS 모두 가능)
  전체 맵을 순회하면서 1을 만났을 때마다 BFS/DFS 수행하여 연결 요소 개수 카운트
  입력 케이스에 따라 map, visited 배열 초기화 필수
  
- 주요 코드/아이디어:
  inputcase를 한번에 처리할 수 있는 방법을 찾는게 중요하다고 생각
  인접행렬 사용 X → visited 배열과 큐 사용
  memset, 전역변수, 큐 활용
- 리뷰 포인트:
  memset 0 을 이용하여 초기화를 하여 사용함
  

### 문제 2: 미로 탐색
- 풀이 접근:
  BFS를 이용한 최단 거리 탐색
  (0,0)에서 (n-1,m-1)까지 도달하는 최단 거리 구하는 문제
  string으로 받는 입력 파싱이 난이도 요소
- 주요 코드/아이디어:
  char temp[]로 입력을 받고, temp[j] - '0'으로 숫자 변환
  map을 갱신하면서 최단 거리 기록
  visited 배열 별도 사용하여 중복 방문 방지
- 리뷰 포인트:
  함수 정의 시 void로 명확하게 적는 습관 추천
  return 없이도 BFS 내부에서 종료 가능 (자연 가지치기)

### 문제 3: 숨바꼭질2
- 풀이 접근:
  BFS를 이용해 최단 시간 + 그 시간으로 도달할 수 있는 방법의 수 계산
- 주요 코드/아이디어:
  visited[] 배열로 시간 저장
  cnt[] 배열로 도달 방법 수 저장
  map 배열 대신 두 개 배열 분리하여 사용
  if (visit[next] == -1) → 처음 방문, else if (visit[next] == visit[curr] + 1) → 다른 경로로 도달한 경우
- 리뷰 포인트:
  visited와 cnt를 분리한 이유: 자기 참조 이슈 방지
  cnt[next] += cnt[curr] 방식으로 여러 경로 누적
  범위 체크 필수: if (next < 0 || next > MAX_N) continue;
  BFS 큐가 커질 수 있으므로 최대 범위 고려 필요
  디버깅 습관: 중간마다 print 찍어 확인하는 연습 추천
  예외 케이스 (start == end) 미리 처리해주는 것이 좋음

---

## 📚 추가 학습/참고
- 
- 

---

## ✅ 다음주 문제 출제자: 최현준
- 다음 주 주제: BFS, 재귀, 이진탐색
- 문제 번호 및 링크:
  1. 문제 1: [정올 #1161 - 하노이1](https://jungol.co.kr/problem/1161?cursor=Niw3LDU=)
  2. 문제 2: [백준 #7795 - 먹을 것인가 먹힐 것인가](https://www.acmicpc.net/problem/7795)
  3. 문제 3: [정올 #1082 - 화염에서탈출(SLIKAR)](https://jungol.co.kr/problem/1082?cursor=OCw3LDU=)
