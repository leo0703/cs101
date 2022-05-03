#include <stdio.h>

int _a(int x, int y) {
    return x + y; 
}
int _b(int x, int y) {
    return x - y; 
}
int _c(int x, int y) {
    return x * y; 
}
int _d(int x, int y) {
    return x / y; 
}
int _e(int x, int y) {
    int sum = 1;
    for(int i = 0; i < y; i++) {
        sum *= x;
    }
    return sum;
}
int main(void) {
    int x, y, choice;
    int (*operation[5])(int, int);
    operation[0] = _a;
    operation[1] = _b;
    operation[2] = _c;
    operation[3] = _d;
    operation[4] = _e;

    printf("Enter two integer: ");
    scanf("%d%d", &x, &y);

    printf("Enter 0:+, 1:-, 2:*, 3:/, 4:^ ");
    scanf("%d", &choice);
    printf("%d", operation[choice](x, y));
    return 0;
}
