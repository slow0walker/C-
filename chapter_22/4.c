#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*
int main(int argc, char* argv[])
{
	FILE* fp;
	int count = 0;
	int ch;

	if (argc < 2)
	{
		printf("usage: count_chars filename\n");
		exit(EXIT_FAILURE);
	}

	if ((fp = fopen(argv[1], "r")) == NULL)
	{
		fprintf(stderr, "can't open %s \n");
		exit(EXIT_FAILURE);
	}
	while ((ch = fgetc(fp)) != EOF)
	{
		count++;
	}
	printf("Number of characters: %d\n", count);
	fclose(fp);
	return 0;
}
*/
/*
int main(int argc, char* argv[]) {
    FILE* fp;
    int count = 0;
    int ch;
    bool in_word = false;

    if (argc != 2) {
        printf("usage: count_words filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (!isspace(ch) && !in_word) {
            in_word = true;
            count++;
        }
        else if (isspace(ch) && in_word) {
            in_word = false;
        }
    }

    printf("Number of words: %d\n", count);
    fclose(fp);
    return 0;
}
*/

int main(int argc, char* argv[]) {
    FILE* fp;
    int count = 0;
    int ch;

    if (argc != 2) {
        printf("usage: count_lines filename\n");
        exit(EXIT_FAILURE);
    }

    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            count++;
        }
    }

    // 若文件最后一行无换行符，需额外加1
    fseek(fp, 0, SEEK_SET);
    int first_char = fgetc(fp);
    if (first_char != EOF) {
        count++;
    }

    printf("Number of lines: %d\n", count);
    fclose(fp);
    return 0;
}
