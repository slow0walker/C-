#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main() {
    // 初始化字母面值数组，索引0对应A，1对应B，…，25对应Z
    int letter_values[26] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
        5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
        1, 4, 4, 8, 4, 10
    };
    char word[20];
    int value = 0, i = 0;

    printf("Enter a word: ");
    scanf("%s", word);

    while (word[i] != '\0') {
        char c = toupper(word[i]);
        value += letter_values[c - 'A'];
        i++;
    }

    printf("Scrabble value: %d\n", value);

    return 0;
}