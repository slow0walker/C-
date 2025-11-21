#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>

time_t make_date(int y, int m, int d)
{
    struct tm t = { 0 };
    t.tm_year = y - 1900;
    t.tm_mon = m - 1;
    t.tm_mday = d;
    return mktime(&t);
}

int main(void)
{
    int y1, m1, d1, y2, m2, d2;

    printf("Enter first date (y m d): ");
    scanf("%d %d %d", &y1, &m1, &d1);

    printf("Enter second date (y m d): ");
    scanf("%d %d %d", &y2, &m2, &d2);

    time_t t1 = make_date(y1, m1, d1);
    time_t t2 = make_date(y2, m2, d2);

    double seconds = difftime(t2, t1);
    double days = seconds / (60 * 60 * 24);

    printf("Difference: %.0f days\n", days);
    return 0;
}
