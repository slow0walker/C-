#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>

int main(void)
{
    int month, day, year, n;
    printf("Enter month day year: ");
    scanf("%d %d %d", &month, &day, &year);
    printf("Enter n: ");
    scanf("%d", &n);

    struct tm t = { 0 };
    t.tm_year = year - 1900;
    t.tm_mon = month - 1;
    t.tm_mday = day + n;   // 直接加 n，交给 mktime 处理溢出

    mktime(&t);

    printf("After %d days: %d-%02d-%02d\n",
        n, t.tm_year + 1900, t.tm_mon + 1, t.tm_mday);

    return 0;
}
