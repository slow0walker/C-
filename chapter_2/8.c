#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    double loan, rate, payment;

    // �����������ʡ��»����
    printf("Enter amount of loan: ");
    scanf("%lf", &loan);
    printf("Enter interest rate: ");
    scanf("%lf", &rate);
    printf("Enter monthly payment: ");
    scanf("%lf", &payment);

    // ���������ʣ�������ת�ٷ������12
    double monthly_rate = (rate / 100.0) / 12.0;

    // ��һ�λ�������
    double balance1 = loan - payment + (loan * monthly_rate);
    // �ڶ��λ�������
    double balance2 = balance1 - payment + (balance1 * monthly_rate);
    // �����λ�������
    double balance3 = balance2 - payment + (balance2 * monthly_rate);

    // ��������������λС����
    printf("Balance remaining after first payment: %.2lf\n", balance1);
    printf("Balance remaining after second payment: %.2lf\n", balance2);
    printf("Balance remaining after third payment: %.2lf\n", balance3);

    return 0;
}