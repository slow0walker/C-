#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100

int main(int argc, char* argv[]) {
    FILE* in_fp, * out_fp;
    unsigned char count, ch;
    char out_filename[MAX_FILENAME_LEN];
    int i, len;

    if (argc != 2) {
        fprintf(stderr, "usage: uncompress_file compressed_file\n");
        exit(EXIT_FAILURE);
    }

    len = strlen(argv[1]);
    if (len < 4 || strcmp(&argv[1][len - 4], ".rle") != 0) {
        fprintf(stderr, "Error: input file must have .rle extension\n");
        exit(EXIT_FAILURE);
    }

    if ((in_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    strncpy(out_filename, argv[1], len - 4);
    out_filename[len - 4] = '\0';
    if ((out_fp = fopen(out_filename, "wb")) == NULL) {
        fprintf(stderr, "Can't create %s\n", out_filename);
        fclose(in_fp);
        exit(EXIT_FAILURE);
    }

    while (fread(&count, 1, 1, in_fp) == 1 && fread(&ch, 1, 1, in_fp) == 1) {
        for (i = 0; i < count; i++) {
            fputc(ch, out_fp);
        }
    }

    fclose(in_fp);
    fclose(out_fp);
    return 0;
}