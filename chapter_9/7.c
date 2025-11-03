#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// µÝ¹é¼ÆËãxµÄn´ÎÃÝ
double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    else if (n % 2 == 0) {
        double half = power(x, n / 2);
        return half * half;
    }
    else {
        return x * power(x, n - 1);
    }
}

int main() {
    double x;
    int n;
    printf("Enter x and n: ");
    scanf("%lf %d", &x, &n);
    printf("x^n = %lf\n", power(x, n));
    return 0;
}