#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void)
{
    double P, r, t;

    printf("Enter P, r (rate), t (years): ");
    scanf("%lf %lf %lf", &P, &r, &t);

    double A = P * exp(r * t);

    printf("Amount after %.2f years = %.2f\n", t, A);
    return 0;
}
