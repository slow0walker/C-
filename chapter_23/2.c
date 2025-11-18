#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char line[1000];

    while (fgets(line, sizeof(line), stdin) != NULL) {
        char* p = line;

        while (*p && isspace((unsigned char)*p))
            p++;

        if (*p)  // ·Ç¿ÕÐÐ
            fputs(p, stdout);
    }
    return 0;
}
