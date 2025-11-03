#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

double polynomial(double x) {
    return 3 * x * x * x*x*x + 2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6;
}

int main() {
    double x;
    printf("Enter the value of x: ");
    scanf("%lf", &x);
    printf("The value of the polynomial is: %.2f\n", polynomial(x));
    return 0;
}