#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    FILE* fp;
    unsigned char ch;
    int offset = 0;
    int count = 0;

    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%-8s %-20s %s\n", "Offset", "Bytes", "Characters");
    while ((ch = fgetc(fp)) != EOF) {
        if (count == 0) {
            printf("%-8d ", offset);
        }
        printf("%02X ", ch);
        putchar(isprint(ch) ? ch : '.');
        count++;
        if (count == 10) {
            putchar('\n');
            offset += 10;
            count = 0;
        }
    }
    if (count != 0) {
        putchar('\n');
    }

    fclose(fp);
    return 0;
}