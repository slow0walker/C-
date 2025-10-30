#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    double x;
    printf("请输入x的值：");
    scanf("%lf", &x);  

    
    double result = (((((3 * x) + 2) * x - 5) * x - 1) * x + 7) * x - 6;

    printf("多项式的值为：%.2lf\n", result);  
    return 0;
}