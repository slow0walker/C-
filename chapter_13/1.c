#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#define MAX_LEN 20

int main() {
    char smallest_word[MAX_LEN], largest_word[MAX_LEN], current_word[MAX_LEN];

    // 读取第一个单词并初始化最小、最大单词
    printf("Enter word: ");
    scanf("%s", current_word);
    strcpy(smallest_word, current_word);
    strcpy(largest_word, current_word);

    while (strlen(current_word) != 4) {
        printf("Enter word: ");
        scanf("%s", current_word);
        if (strlen(current_word) == 4) break;

        // 比较并更新最小单词
        if (strcmp(current_word, smallest_word) < 0) {
            strcpy(smallest_word, current_word);
        }
        // 比较并更新最大单词
        if (strcmp(current_word, largest_word) > 0) {
            strcpy(largest_word, current_word);
        }
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

    return 0;
}
