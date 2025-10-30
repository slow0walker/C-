#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main(void) {
    float commission, rival_commission, value;
    int shares;      // 股票数量
    float price;     // 每股价格

    // 输入股票数量和每股价格
    printf("Enter number of shares: ");
    scanf("%d", &shares);
    printf("Enter price per share: ");
    scanf("%f", &price);

    // 计算交易额
    value = shares * price;

    // 计算原经纪人佣金（逻辑与原程序一致）
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

    // 确保最低佣金为39美元
    if (commission < 39.00f)
        commission = 39.00f;

    // 计算竞争对手的佣金
    if (shares < 2000)
        rival_commission = shares * 33.03f;
    else
        rival_commission = shares * 33.02f;

    // 输出结果
    printf("Original Commission: $%.2f\n", commission);
    printf("Rival Commission: $%.2f\n", rival_commission);

    return 0;
}