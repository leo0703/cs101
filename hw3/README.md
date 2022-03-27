#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
 
    clock_t start, end;
    
    start = clock(); 
    
    void hanoi(int n, char A, char B, char C) {
    if(n == 1) {
    printf("Move sheet from %c to %c\n", A, C);
    }
    else {
    hanoi(n-1, A, C, B);
    hanoi(1, A, B, C);
    hanoi(n-1, B, A, C);
        }
    }

    int n;
    printf("請輸入盤數：");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    
    end = clock();

    double diff = end - start; 
    printf(" %f  秒", diff / CLOCKS_PER_SEC );
    return 0;
}