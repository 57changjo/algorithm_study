# 📆 Week 6 스터디 정리

## 📌 주제
- 이번 주 주제: DFS, 우선순위 큐, 이진 탐색
- 출제자: 김다경

---

## 📂 다룬 문제
1. [정올 1409 - 벽장문의 이동](https://jungol.co.kr/problem/1409?cursor=OCw1LDY%3D)
2. [백준 1715 - 카드 정렬하기](https://www.acmicpc.net/problem/1715)
3. [백준 10816 - 숫자 카드 2](https://www.acmicpc.net/problem/10816)

---

## 📊 발표 담당
- 문제 1: 박민우
- 문제 2: 조윤서
- 문제 3: 최현준

---

## 📝 리뷰 요약
- 정리 담당: 홍시은
### 문제 1: 문제명
- 풀이 접근: DFS, cost를 벽장문1, 2에 대해 거리를 계산하고 비교하여 최솟값을 가지고 횟수를 갱신한다.
- 주요 코드/아이디어:
  - opened_door1, opened_door2 (열려 있는 문), index (사용할 벽장 순서 index)을 DFS 함수 파라미터로 사용
  - opened_door1_cost, opened_door2_cost: 열려 있는 두 문과 사용할 벽장 거리
  - opened_door1_cost_total, opened_door2_cost_total: 앞선 cost를 가지고 최소 이동 거리를 갱신하여 둘 중 작은 값을 return
- 리뷰 포인트: 민우님 코드 방식이 다른 문제에서 사용하기에는 안전하지 않아서 유의해야한다. 따라서 DFS의 종료조건 안에서 값을 갱신하는 보편적인 방법을 사용하자.

### 문제 2: 문제명
- 풀이 접근: 우선순위 큐 or 최솟값 2개 뽑아서 더하기
- 주요 코드/아이디어:
  - 최솟값 아이디어 - while 안에서 qsort로 정렬을 해서 최솟값 2개를 뽑아서 더하기, 뽑힌 자리는 앞으로 땡겨오기
- 리뷰 포인트: 

### 문제 3: 문제명
- 풀이 접근: 이진 탐색, upper, lower 활용하기
- 주요 코드/아이디어: 
- 리뷰 포인트: 

---

## 📚 추가 학습/참고
- (예: 시간복잡도 개념 정리 필요 → docs/algorithm_notes.md 반영 예정)
- (예: 문자열 문제 접근 시 카운팅/정렬 두 방식 비교)
- p2: 최악의 시간 복잡도
---

## ✅ 다음주 문제 출제자: 조민창
- 다음 주 주제: Dynamic Programming
- 문제 번호 및 링크:
  1. 문제 1: [백준 12865 - 평범한 배낭](https://www.acmicpc.net/problem/12865)
  2. 문제 2: [백준 1149 - RGB거리](https://www.acmicpc.net/problem/1149)
  3. 문제 3: [백준 2293 - 동전 1](https://www.acmicpc.net/problem/2293)
