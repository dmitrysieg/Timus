#include <stdio.h>

void fill(int *a, int size, int val) {
    for (int i = 0; i < size; i++) {
        a[i] = val;
    }
}

void loopPrint(int digit, int times) {
    for (int i = 0; i < times; i++) {
        printf("%d", digit);
    }
}

int main() {
    long x;
    scanf("%d", &x);
    
    if (x == 0) {
        printf("10");
        return 0;
    }
    
    if (x == 1) {
        printf("1");
        return 0;
    }
    
    int a[10];
    int isFineStep = 0;
    
    fill(a, 10, 0);
    
    do {
        isFineStep = 0;
        for (int i = 9; i >= 2; i--) {
            if (x % i == 0) {
                isFineStep = 1;
                a[i]++;
                x = x / i;
                break;
            }
        }
    } while (isFineStep && x != 1);
    
    if (!isFineStep) {
        printf("-1");
        return 0;
    }
    
    for (int i = 2; i <= 9; i++) {
        if (a[i] > 0) {
            loopPrint(i, a[i]);
        }
    }
    return 0;
}