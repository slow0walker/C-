#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int c, prev = 0, count = 0;

    while ((c = getchar()) != EOF) {
        if ((prev == '.' || prev == '?' || prev == '!') && isspace(c))
            count++;
        prev = c;
    }

    printf("Sentences: %d\n", count);
    return 0;
}
