#define _CRT_SECURE_NO_WARNINGS 1
#include <time.h>

time_t year_start(int year)
{
    struct tm t = { 0 };

    t.tm_year = year - 1900;  // 从 1900 开始
    t.tm_mon = 0;            // 1月
    t.tm_mday = 1;            // 1日
    t.tm_hour = 0;
    t.tm_min = 0;
    t.tm_sec = 0;
    t.tm_isdst = -1;          // 让库自动计算 DST

    return mktime(&t);
}
