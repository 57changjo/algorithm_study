#include <stdio.h>
#define OFFSET 10000000
#define MAX 20000001  // -10,000,000 ~ 10,000,000 

int countArr[MAX]; 
int main() {
    int N, M, num;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &num);
        countArr[num + OFFSET]++;  
    }

    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        scanf("%d", &num);
        printf("%d ", countArr[num + OFFSET]);
    }

    return 0;
}
