#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void) {
    float loan, interestRate, monthlyPayment;
    int numPayments;
    int i;

    printf("Enter amount of loan: ");
    scanf("%f", &loan);
    printf("Enter interest rate: ");
    scanf("%f", &interestRate);
    printf("Enter monthly payment: ");
    scanf("%f", &monthlyPayment);
    printf("Enter number of payments: ");
    scanf("%d", &numPayments);

    float monthlyRate = interestRate / 100 / 12;

    for (i = 1; i <= numPayments; i++) {
        loan = loan * (1 + monthlyRate) - monthlyPayment;
        printf("Balance remaining after %d payment: $%.2f\n", i, loan);
    }

    return 0;
}