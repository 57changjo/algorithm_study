#include <stdio.h>

void hanoi(int n, int a, int b, int c) {
    if (n == 1) { 
        printf("%d : %d -> %d\n", n, a, b);
    }
    else {
        hanoi(n - 1, a, c, b);
        printf("%d : %d -> %d\n", n, a, b); 
        hanoi(n - 1, c, b, a); 
    }
}

int main(void)
{
   int n;
   scanf("%d", &n);
   hanoi(n, 1, 3, 2); 

   return 0;
}
