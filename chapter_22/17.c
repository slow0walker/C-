#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    char line[100], digits[11];
    int digit_count;
    while (fgets(line, sizeof(line), fp) != NULL) {
        digit_count = 0;
        for (int i = 0; line[i] != '\0' && digit_count < 10; i++) {
            if (isdigit(line[i])) {
                digits[digit_count++] = line[i];
            }
        }
        if (digit_count == 10) {
            printf("(%c%c%c) %c%c%c-%c%c%c%c\n",
                digits[0], digits[1], digits[2],
                digits[3], digits[4], digits[5],
                digits[6], digits[7], digits[8], digits[9]);
        }
        else {
            fprintf(stderr, "Invalid phone number: %s", line);
        }
    }

    fclose(fp);
    return 0;
}