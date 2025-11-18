#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_WORDS 100
#define MAX_WORD_LEN 50

int read_line(FILE* fp, char* line, int max_len) {
    int ch, i = 0;
    while ((ch = fgetc(fp)) != EOF && ch != '\n' && i < max_len - 1) {
        line[i++] = ch;
    }
    line[i] = '\0';
    return i;
}

void justify_line(char* line, int line_len, int max_len) {
    if (line_len == 0) return;
    int num_spaces = 0, num_words = 0;
    char* words[MAX_WORDS];
    char* p = line;

    while (*p) {
        while (*p && isspace(*p)) p++;
        if (*p) {
            words[num_words++] = p;
            while (*p && !isspace(*p)) p++;
            if (*p) *p++ = '\0';
            num_spaces++;
        }
    }
    num_spaces--;

    int extra_spaces = max_len - line_len;
    int spaces_per_gap = num_spaces > 0 ? extra_spaces / num_spaces : 0;
    int rem_spaces = num_spaces > 0 ? extra_spaces % num_spaces : 0;

    p = line;
    for (int i = 0; i < num_words; i++) {
        strcpy(p, words[i]);
        p += strlen(words[i]);
        if (i < num_words - 1) {
            int spaces = spaces_per_gap + (rem_spaces-- > 0 ? 1 : 0);
            memset(p, ' ', spaces);
            p += spaces;
        }
    }
    memset(p, ' ', max_len - (p - line));
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "usage: %s input_file output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    FILE* in_fp = fopen(argv[1], "r");
    FILE* out_fp = fopen(argv[2], "w");
    if (in_fp == NULL || out_fp == NULL) {
        fprintf(stderr, "File open error\n");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE];
    while (read_line(in_fp, line, MAX_LINE) > 0) {
        justify_line(line, strlen(line), 60); // 假设最大行宽60，可根据需求调整
        fprintf(out_fp, "%s\n", line);
    }

    fclose(in_fp);
    fclose(out_fp);
    return 0;
}