#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_N (100000 + 1)
typedef long long ll;

int N;
ll heap[MAX_N];
int heap_size = 0;

// 새 원소 push
void push(ll item) {
    heap[++heap_size] = item;
    int child = heap_size;
    int parent = child / 2;

    while (child > 1 && (heap[parent] > heap[child])) {
        ll temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        child = parent;
        parent = child / 2;
    }
}

// 루트 pop
ll pop(void) {
    if (heap_size == 0) return 0;

    ll result = heap[1];
    heap[1] = heap[heap_size];
    heap_size--;

    int parent = 1;
    int child;
    while (1) {
        child = parent * 2;
        // 왼쪽, 오른쪽 자식 비교 후 작은 쪽 자식 선택
        if ((child + 1 <= heap_size) && (heap[child] > heap[child + 1])) {
            child++;
        }
        // parent가 자식이 없거나, 힙 속성을 만족할 때까지
        if ((child > heap_size) || (heap[parent] < heap[child])) {
            break;
        }

        ll temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        parent = child;
    }
    return result;
}

void inputData(void) {
    (void)scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int card_deck;
        (void)scanf("%d", &card_deck);
        push(card_deck);
    }
}

int main(void) {
    //(void)freopen("b1715.txt", "r", stdin);
    inputData();

    ll total_cost = 0;
    ll deck1 = 0;
	ll deck2 = 0;
	ll new_deck = 0;

    // N이 1인 경우 비교 횟수는 0
    if (N == 1) {
        printf("0\n");
        return 0;
    }

    while (heap_size > 1) {
        deck1 = pop();
        deck2 = pop();

        new_deck = deck1 + deck2;
        total_cost += new_deck;

        push(new_deck);
    }

    printf("%lld", total_cost);

    return 0;
}

#endif
