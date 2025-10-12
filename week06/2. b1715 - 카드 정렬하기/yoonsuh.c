#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int N;
    scanf("%d", &N);

    int cards[100000];
    for (int i = 0; i < N; i++) {
        scanf("%d", &cards[i]);
    }

    qsort(cards, N, sizeof(int), compare);

    int total = 0;
    int size = N;

    while (size > 1) {
        int sum = cards[0] + cards[1];
        total += sum;

        cards[0] = sum;
        for (int i = 1; i < size - 1; i++)
            cards[i] = cards[i + 1];
        size--;

        qsort(cards, size, sizeof(int), compare);
    }

    printf("%d\n", total);
    return 0;
}
