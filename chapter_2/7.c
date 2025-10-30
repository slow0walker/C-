#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int amount;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);  

    // 计算20美元钞票数
    int bill20 = amount / 20;
    amount = amount % 20;  // 剩余金额

    // 计算10美元钞票数
    int bill10 = amount / 10;
    amount = amount % 10;

    // 计算5美元钞票数
    int bill5 = amount / 5;
    amount = amount % 5;

    // 计算1美元钞票数
    int bill1 = amount;  // 剩余金额即为1美元张数

    // 输出结果
    printf("$20 bills: %d\n", bill20);
    printf("$10 bills: %d\n", bill10);
    printf("$5 bills: %d\n", bill5);
    printf("$1 bills: %d\n", bill1);

    return 0;
}