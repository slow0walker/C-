#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s windows_file unix_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* in = fopen(argv[1], "rb");
    FILE* out = fopen(argv[2], "wb");
    if (in == NULL || out == NULL) {
        fprintf(stderr, "File open error\n");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        if (ch != '\r') {
            fputc(ch, out);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s unix_file windows_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* in = fopen(argv[1], "rb");
    FILE* out = fopen(argv[2], "wb");
    if (in == NULL || out == NULL) {
        fprintf(stderr, "File open error\n");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        if (ch == '\n') {
            fputc('\r', out);
        }
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}