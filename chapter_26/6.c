#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    char buf[100];

    // (a) Sunday, June 3, 2007 05:48p
    strftime(buf, sizeof(buf), "%A, %B %d, %Y %I:%M%p", t);
    printf("%s\n", buf);

    // (b) Sun, 3 Jun 07 17:48
    strftime(buf, sizeof(buf), "%a, %d %b %y %H:%M", t);
    printf("%s\n", buf);

    // (c) 06/03/07 5:48:34 PM
    strftime(buf, sizeof(buf), "%m/%d/%y %I:%M:%S %p", t);
    printf("%s\n", buf);

    return 0;
}
