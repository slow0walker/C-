#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    double loan, rate, payment;

    // 输入贷款金额、利率、月还款额
    printf("Enter amount of loan: ");
    scanf("%lf", &loan);
    printf("Enter interest rate: ");
    scanf("%lf", &rate);
    printf("Enter monthly payment: ");
    scanf("%lf", &payment);

    // 计算月利率：年利率转百分数后÷12
    double monthly_rate = (rate / 100.0) / 12.0;

    // 第一次还款后余额
    double balance1 = loan - payment + (loan * monthly_rate);
    // 第二次还款后余额
    double balance2 = balance1 - payment + (balance1 * monthly_rate);
    // 第三次还款后余额
    double balance3 = balance2 - payment + (balance2 * monthly_rate);

    // 输出结果（保留两位小数）
    printf("Balance remaining after first payment: %.2lf\n", balance1);
    printf("Balance remaining after second payment: %.2lf\n", balance2);
    printf("Balance remaining after third payment: %.2lf\n", balance3);

    return 0;
}