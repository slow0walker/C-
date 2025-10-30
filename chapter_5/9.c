#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    int m1, d1, y1, m2, d2, y2;

    // 输入第一个日期
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m1, &d1, &y1);

    // 输入第二个日期
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &m2, &d2, &y2);

    // 先比较年份，年份小的日期更早
    if (y1 < y2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
    }
    else if (y1 > y2) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
    }
    else {
        // 年份相同，比较月份
        if (m1 < m2) {
            printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
        }
        else if (m1 > m2) {
            printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
        }
        else {
            // 月份也相同，比较日期
            if (d1 < d2) {
                printf("%d/%d/%d is earlier than %d/%d/%d\n", m1, d1, y1, m2, d2, y2);
            }
            else if (d1 > d2) {
                printf("%d/%d/%d is earlier than %d/%d/%d\n", m2, d2, y2, m1, d1, y1);
            }
            else {
                printf("The two dates are the same.\n");
            }
        }
    }

    return 0;
}