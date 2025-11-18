#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100

int main(void)
{
    char line[1000];
    char* words[MAX_WORDS];
    int count = 0;

    printf("Enter words: ");
    fgets(line, sizeof(line), stdin);

    char* token = strtok(line, " \t\n");
    while (token != NULL && count < MAX_WORDS) {
        words[count++] = token;
        token = strtok(NULL, " \t\n");
    }

    for (int i = count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i != 0) printf(" ");
    }
    printf("\n");
    return 0;
}
