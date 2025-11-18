#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100

int main(int argc, char* argv[]) {
    FILE* in_fp, * out_fp;
    unsigned char curr, prev;
    int count;
    char out_filename[MAX_FILENAME_LEN];

    if (argc != 2) {
        fprintf(stderr, "usage: compress_file filename\n");
        exit(EXIT_FAILURE);
    }

    if ((in_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    sprintf(out_filename, "%s.rle", argv[1]);
    if ((out_fp = fopen(out_filename, "wb")) == NULL) {
        fprintf(stderr, "Can't create %s\n", out_filename);
        fclose(in_fp);
        exit(EXIT_FAILURE);
    }

    if (fgetc(in_fp) == EOF) {
        fclose(in_fp);
        fclose(out_fp);
        return 0;
    }
    prev = (unsigned char)fseek(in_fp, -1, SEEK_CUR); // 回退一个字节
    count = 1;

    while ((curr = fgetc(in_fp)) != EOF) {
        if (curr == prev && count < 255) {
            count++;
        }
        else {
            fputc(count, out_fp);
            fputc(prev, out_fp);
            prev = curr;
            count = 1;
        }
    }
    fputc(count, out_fp);
    fputc(prev, out_fp);

    fclose(in_fp);
    fclose(out_fp);
    return 0;
}