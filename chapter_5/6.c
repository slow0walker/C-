#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, check_digit;
    int first_sum, second_sum, total, calculated_check_digit;

    printf("Enter the UPC (including check digit, e.g., d i1 i2 i3 i4 i5 j1 j2 j3 j4 j5 check_digit): ");
    scanf("%d %d%d%d%d%d %d%d%d%d%d %d", &d, &i1, &i2, &i3, &i4, &i5, &j1, &j2, &j3, &j4, &j5, &check_digit);

    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;
    calculated_check_digit = 9 - ((total - 1) % 10);

    if (calculated_check_digit == check_digit)
        printf("VALID\n");
    else
        printf("NOT VALID\n");

    return 0;
}