#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

// 定义日期结构，包含年、月、日
struct Date {
    int year;
    int month;
    int day;
};

// 比较两个日期的函数
int compare_dates(struct Date d1, struct Date d2) {
    if (d1.year != d2.year)
        return d1.year - d2.year;
    if (d1.month != d2.month)
        return d1.month - d2.month;
    return d1.day - d2.day;
}

// 示例：用户输入日期并比较
int main() {
    struct Date input_date, target_date = { 2025, 11, 9 };

    printf("请输入年、月、日：");
    scanf("%d %d %d", &input_date.year, &input_date.month, &input_date.day);

    int result = compare_dates(input_date, target_date);
    if (result > 0)
        printf("输入日期在目标日期之后\n");
    else if (result < 0)
        printf("输入日期在目标日期之前\n");
    else
        printf("输入日期与目标日期相同\n");

    return 0;
}