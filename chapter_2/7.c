#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int amount;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);  

    // ����20��Ԫ��Ʊ��
    int bill20 = amount / 20;
    amount = amount % 20;  // ʣ����

    // ����10��Ԫ��Ʊ��
    int bill10 = amount / 10;
    amount = amount % 10;

    // ����5��Ԫ��Ʊ��
    int bill5 = amount / 5;
    amount = amount % 5;

    // ����1��Ԫ��Ʊ��
    int bill1 = amount;  // ʣ���Ϊ1��Ԫ����

    // ������
    printf("$20 bills: %d\n", bill20);
    printf("$10 bills: %d\n", bill10);
    printf("$5 bills: %d\n", bill5);
    printf("$1 bills: %d\n", bill1);

    return 0;
}