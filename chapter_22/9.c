#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 25

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

// º¯ÊýÉùÃ÷
void merge_files(const char* file1, const char* file2, const char* out_file);
int read_part(FILE* fp, struct part* p);
void write_part(FILE* fp, const struct part* p);

int main(int argc, char* argv[]) {
    if (argc != 4) {
        fprintf(stderr, "usage: %s file1 file2 output_file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    merge_files(argv[1], argv[2], argv[3]);
    return 0;
}

void merge_files(const char* file1, const char* file2, const char* out_file) {
    FILE* fp1, * fp2, * fout;
    struct part p1, p2;
    int eof1 = 0, eof2 = 0;

    if ((fp1 = fopen(file1, "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file1);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(file2, "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", file2);
        fclose(fp1);
        exit(EXIT_FAILURE);
    }
    if ((fout = fopen(out_file, "wb")) == NULL) {
        fprintf(stderr, "Can't create %s\n", out_file);
        fclose(fp1);
        fclose(fp2);
        exit(EXIT_FAILURE);
    }

    eof1 = read_part(fp1, &p1);
    eof2 = read_part(fp2, &p2);

    while (!eof1 && !eof2) {
        if (p1.number < p2.number) {
            write_part(fout, &p1);
            eof1 = read_part(fp1, &p1);
        }
        else if (p1.number > p2.number) {
            write_part(fout, &p2);
            eof2 = read_part(fp2, &p2);
        }
        else {
            if (strcmp(p1.name, p2.name) != 0) {
                fprintf(stderr, "Error: Mismatched part names for number %d\n", p1.number);
                fclose(fp1);
                fclose(fp2);
                fclose(fout);
                exit(EXIT_FAILURE);
            }
            p1.on_hand += p2.on_hand;
            write_part(fout, &p1);
            eof1 = read_part(fp1, &p1);
            eof2 = read_part(fp2, &p2);
        }
    }

    while (!eof1) {
        write_part(fout, &p1);
        eof1 = read_part(fp1, &p1);
    }
    while (!eof2) {
        write_part(fout, &p2);
        eof2 = read_part(fp2, &p2);
    }

    fclose(fp1);
    fclose(fp2);
    fclose(fout);
}

int read_part(FILE* fp, struct part* p) {
    if (fread(&p->number, sizeof(int), 1, fp) != 1) return 1;
    if (fread(p->name, sizeof(char), NAME_LEN + 1, fp) != NAME_LEN + 1) return 1;
    if (fread(&p->on_hand, sizeof(int), 1, fp) != 1) return 1;
    return 0;
}

void write_part(FILE* fp, const struct part* p) {
    fwrite(&p->number, sizeof(int), 1, fp);
    fwrite(p->name, sizeof(char), NAME_LEN + 1, fp);
    fwrite(&p->on_hand, sizeof(int), 1, fp);
}