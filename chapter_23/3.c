#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c, prev = ' ';

    while ((c = getchar()) != EOF) {
        if (isspace(prev) && isalpha(c))
            c = toupper(c);
        putchar(c);
        prev = c;
    }
    return 0;
}
