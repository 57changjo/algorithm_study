#include <stdio.h>
int main(void) {
    int n, x;
    int count;

    scanf_s("%d", &n);
    int arr[100000]; 

    for (int i = 0; i < n; i++) {
        scanf_s("%d ", &arr[i]);
    }
    scanf_s("%d", &x);

    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == x) {
                count++;
            }
        }
    }

    printf("%d\n", count);
    return 0;
}
