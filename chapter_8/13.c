#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 20

int main() {
    char first[20], last[MAX_LEN];
    char input[50];

    printf("Enter a first and last name: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0;  // 去除换行符

    // 提取名的首字母
    char first_initial = toupper(input[0]);

    // 提取姓并存储到数组
    char* space = strrchr(input, ' ');
    if (space != NULL) {
        strncpy(last, space + 1, MAX_LEN - 1);
        last[MAX_LEN - 1] = '\0';
    }
    else {
        strcpy(last, "");
    }

    printf("You entered the name: %s, %c.\n", last, first_initial);

    return 0;
}