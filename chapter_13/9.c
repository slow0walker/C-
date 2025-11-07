#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int compute_vowel_count(const char* sentence) {
    int count = 0;
    while (*sentence != '\0') {
        char c = tolower((unsigned char)*sentence);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            count++;
        }
        sentence++;
    }
    return count;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    // 读取整行输入（包含空格）
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < 999) {
        sentence[i++] = ch;
    }
    sentence[i] = '\0';

    int vowel_count = compute_vowel_count(sentence);
    printf("Your sentence contains %d vowels.\n", vowel_count);

    return 0;
}