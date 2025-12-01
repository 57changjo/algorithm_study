# 📆 Week 12 스터디 정리

## 📌 주제
- 이번 주 주제: (정리 시 채우기!)
- 출제자: 김다경

---

## 📂 다룬 문제
1. [백준 3896 - 소수 사이 수](https://www.acmicpc.net/problem/3896)
2. [백준 15989 - 1, 2, 3 더하기 4](https://www.acmicpc.net/problem/15989)
3. [백준 14719 - 빗물](https://www.acmicpc.net/problem/14719)
---

## 📊 발표 담당
- 문제 1: 조윤서
- 문제 2: 최현준
- 문제 3: 홍시은

---

## 📝 리뷰 요약
- 정리 담당: 전진
### 문제 1: [백준 3896 - 소수 사이 수]

- 풀이 접근: 
1) 소수를 처리할 수 있는 에라토스테네스 체를 알 고 있는가?
2) 어떠한 정수가 나왔을때 그것과 가장 가까운 소수 두개를 찾을 수 있는가?

- 주요 코드/아이디어:

```
// 에라토스테네스의 체
    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
```

- 리뷰 포인트:
1) 시간 초과를 해결 할 수 있는지 -> 이분탐색
2) 음수가 아닌 정수중 소수만을 구할 수 있는지
3) 어떠한 수가 정해졌을때 이보다 큰 수와 작은 수가 들어 있는 배열의 인덱스를 구할 수 있는지
4) lower, upper bound 를 이용할 수 있는지 -> 알고리즘.헤더파일

### 문제 2: [백준 15989 - 1, 2, 3 더하기 4]
- 풀이 접근:
1) dp 문제로서 접근
2) 점화식을 어떻게 세울 것인가? (1로만 인지? , 1과 2로 구성되었는지, 1,2,3으로 이루어져있는지)
3) dp로 접근하는 방식 또는 점화식으로 문제를 풀든 하나하나 이를 써가면서 점화식을 구할 수 있다.

- 주요 코드/아이디어:
```
int solve() {
	int temp = 0;
	int ans = 0;
	for (int i = 0; i <= n/3 ; i++) {  // 3을 사용하는 경우(i=0에서는 2, 1만 사용하는 경우 뽑아줌)
		temp = n - (3 * i);
		ans += temp / 2 + 1;			// i=0에서는 1으로만 채우는 경우 1가지 추가, i>=1에서는 3+1의 조합 1가지 추가
	}

	return ans;
}
```
-----------------------------------------------------------------------------------------

```
 //(void)freopen("b15989.txt", "r", stdin);
    cin >> T;

    DP[5] = 1; // 숫자 0 의 DP
    for (int i = 6; i <= 10005; i++) {
        DP[i] = DP[i - 1] + DP[i - 2] - DP[i - 4] - DP[i - 5] + DP[i - 6];
    }
``` 

- 리뷰 포인트:
1) 숫자에서 3을 나누었을때 몫의 수만큼 이를 내부적으로 계산해나가며 이에 대한 case를 ans에 누적
-> HJ
2) dp의 방식에서 1로만 이루어질때 2,3으로 이루어질때(3만으로 구성되면 안됌). 3으로만 이루어질때를 각각 점화식으로 구하여 이에 대한 것을 누적 하며 결과를 구성 ->DK
3) 	ios::sync_with_stdio(false);
	cin.tie(nullptr);
=> 반드시 할것!!

### 문제 3: [백준 14719 - 빗물]

- 풀이 접근:
1) solve1를 보면 for문을 통해 i를 이동해가며 left와 right를 통해 i를 기준으로 왼쪽 오른쪽에 대한 가장 높은 값을 찾는다.
2) 좌측 우측 벽일 경우는 case를 제외한다.
3) solve2를 보면 반복문을 통해 더 낮은쪽을 먼저 선정하여 left를 움직이면서 더 큰 것을 만날때 이를 갱신하면서 계속해서 진행

- 주요 코드/아이디어:

```
// 가장 직관적인 풀이 - O(N^2)
int solve1() {
	int rain = 0;

	for (int i = 1; i < W - 1; i++) {
		int left = 0, right = 0;
		for (int j = 0; j < i; j++) {
			left = max(left, height[j]);
		}
		for (int j = W - 1; j > i; j--) {
			right = max(right, height[j]);
		}
		rain += max(0, min(left, right) - height[i]);
	}

	return rain;
}


// 투 포인터 풀어 - O(N)
int solve2() {
	int left = 0, right = W - 1;
	int left_max = 0, right_max = 0;
	int rain = 0;

	while (left < right) {
		// 왼쪽 - 더 낮은 쪽을 먼저
		if (height[left] <= height[right]) {
			if (height[left] >= left_max) {
				left_max = height[left];
			}
			else {
				rain += left_max - height[left];
			}
			left++;
		}
		// 오른쪽
		else {
			if (height[right] >= right_max) {
				right_max = height[right];
			}
			else {
				rain += right_max - height[right];
			}
			right--;
		}
	}

	return rain;
}
```

- 리뷰 포인트:
1) 기준을 가지고 움직여 가며, 이에 대한 높이를 갱신하여 빗물을 구하자
2) 다양한 이진정렬 문제를 통해 문제해결 능력을 기를 수 있다!
3) 빗물을 받는 상자를 90도 회전시켜 검정 상자가 1개일때 그리고 검정 상자가 가득 찰때를 제외하고 start와 end사이의 차를 확인하여 이 사이에 빗물을 count 해준다.
---

## 📚 추가 학습/참고
- 이진 탐색에 대한 함수 API 확인할 것.
- DP와 점화식을 구해보자!!

---

## ✅ 다음주 문제 출제자: 조민창
- 문제 번호 및 링크:
  1. 문제 1: [백준 16918 - 봄버맨](https://www.acmicpc.net/problem/16918)
  2. 문제 2: [백준 15686 - 치킨 배달](https://www.acmicpc.net/problem/15686)
  3. 문제 3: [백준 20055 - 컨베이어 벨트 위의 로봇](https://www.acmicpc.net/problem/20055)
