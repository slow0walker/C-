#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char in_filename[100], out_filename[100];
    int shift;
    FILE* in_fp, * out_fp;
    int ch;

    printf("Enter name of file to be encrypted: ");
    scanf("%s", in_filename);
    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    sprintf(out_filename, "%s.enc", in_filename);

    if ((in_fp = fopen(in_filename, "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", in_filename);
        exit(EXIT_FAILURE);
    }
    if ((out_fp = fopen(out_filename, "w")) == NULL) {
        fprintf(stderr, "Can't create %s\n", out_filename);
        fclose(in_fp);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(in_fp)) != EOF) {
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            ch = (ch - base + shift) % 26 + base;
        }
        fputc(ch, out_fp);
    }

    fclose(in_fp);
    fclose(out_fp);
    return 0;
}