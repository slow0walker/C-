#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main() {
    double x, y = 1, y_old;
    printf("Enter a positive number: ");
    scanf("%lf", &x);
    do {
        y_old = y;
        y = (y + x / y) / 2;
    } while (fabs(y - y_old) > 0.00001);
    printf("Square root: %.5f\n", y);
    return 0;
}