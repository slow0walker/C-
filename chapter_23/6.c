#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c;
    while ((c = getchar()) != EOF) {
        if (iscntrl(c) && c != '\n')
            putchar('?');
        else
            putchar(c);
    }
    return 0;
}
