// b1715 - 카드 정렬하기
// gpt 코드입니다. 참고용입니다.

#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000

int heap[MAX + 1];
int heap_size = 0;

void push(int x) {
    int i = ++heap_size;
    while (i != 1 && x < heap[i / 2]) {
        heap[i] = heap[i / 2];
        i /= 2;
    }
    heap[i] = x;
}

int pop() {
    int ret = heap[1];
    int temp = heap[heap_size--];
    int parent = 1, child = 2;

    while (child <= heap_size) {
        if (child < heap_size && heap[child] > heap[child + 1])
            child++;
        if (temp <= heap[child])
            break;
        heap[parent] = heap[child];
        parent = child;
        child *= 2;
    }
    heap[parent] = temp;
    return ret;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        push(x);
    }

    long long total = 0;

    // 묶음이 하나 남을 때까지 반복
    while (heap_size > 1) {
        int a = pop();
        int b = pop();
        total += (a + b);
        push(a + b);
    }

    printf("%lld\n", total);
    return 0;
}

#endif
