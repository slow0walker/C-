#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

double calculate_tax(double income) {
    if (income <= 750) {
        return income * 0.01;
    }
    else if (income <= 2250) {
        return 7.50 + (income - 750) * 0.02;
    }
    else if (income <= 3750) {
        return 37.50 + (income - 2250) * 0.03;
    }
    else if (income <= 5250) {
        return 82.50 + (income - 3750) * 0.04;
    }
    else if (income <= 7000) {
        return 142.50 + (income - 5250) * 0.05;
    }
    else {
        return 230.00 + (income - 7000) * 0.06;
    }
}

int main() {
    double income;
    printf("Enter taxable income: ");
    scanf("%lf", &income);
    printf("Tax: $%.2f\n", calculate_tax(income));
    return 0;
}