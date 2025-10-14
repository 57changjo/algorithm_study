#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int N;

int cards[100001];
int heap[100001];
int heap_size = 0;
int total = 0;

void swap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

void push(int x) {

	heap_size++;
	heap[heap_size] = x;
	int i = heap_size;

	while (i > 1 && heap[i] < heap[i / 2]) {
		swap(&heap[i], &heap[i / 2]);
		i = i / 2;
	}
}

int pop(void) {

	int root = heap[1];
	heap[1] = heap[heap_size--];

	int i = 1;

	while (1) {
		int left = i * 2;
		int right = i * 2 + 1;
		int min_child;

		if (left > heap_size) break;
		else if (right > heap_size) min_child = left;
		else min_child = (heap[left] < heap[right]) ? left : right;

		if (heap[i] <= heap[min_child]) break;
		swap(&heap[i], &heap[min_child]);
		i = min_child;
	}
	return root;
}

int main(void) {
	
	(void)scanf("%d", &N);

	for (int i = 0; i < N; i++) {

		(void)scanf("%d", &cards[i]);
	}

	for (int i = 0; i < N; i++) {
		push(cards[i]);
	}

	while (heap_size > 1) {
		int a = pop();
		int b = pop();
		int sum = a + b;
		total += sum;
		push(sum);
	}

	printf("%d", total);

	return 0;
}
#endif
