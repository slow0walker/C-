#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void) {
    float commission, rival_commission, value;
    int shares;      // ��Ʊ����
    float price;     // ÿ�ɼ۸�

    // �����Ʊ������ÿ�ɼ۸�
    printf("Enter number of shares: ");
    scanf("%d", &shares);
    printf("Enter price per share: ");
    scanf("%f", &price);

    // ���㽻�׶�
    value = shares * price;

    // ����ԭ������Ӷ���߼���ԭ����һ�£�
    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;

    // ȷ�����Ӷ��Ϊ39��Ԫ
    if (commission < 39.00f)
        commission = 39.00f;

    // ���㾺�����ֵ�Ӷ��
    if (shares < 2000)
        rival_commission = shares * 33.03f;
    else
        rival_commission = shares * 33.02f;

    // ������
    printf("Original Commission: $%.2f\n", commission);
    printf("Rival Commission: $%.2f\n", rival_commission);

    return 0;
}