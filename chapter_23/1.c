#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>

int main(void)
{
    double a, b, c;
    printf("Enter a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    double discriminant = b * b - 4 * a * c;

    if (a == 0) {
        printf("Not a quadratic equation.\n");
        return 0;
    }

    if (discriminant < 0) {
        printf("Roots are complex.\n");
    }
    else {
        double r1 = (-b + sqrt(discriminant)) / (2 * a);
        double r2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots: %.6f  %.6f\n", r1, r2);
    }
    return 0;
}
