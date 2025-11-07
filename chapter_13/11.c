#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

double compute_average_word_length(const char* sentence) {
    int word_count = 0;
    int char_count = 0;
    bool in_word = false;

    while (*sentence != '\0') {
        if (isalpha((unsigned char)*sentence) || ispunct((unsigned char)*sentence)) {
            char_count++;
            in_word = true;
        }
        else if (in_word) {
            word_count++;
            in_word = false;
        }
        sentence++;
    }
    if (in_word) word_count++; // 处理最后一个单词

    return word_count == 0 ? 0 : (double)char_count / word_count;
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    // 读取整行输入
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n' && i < 999) {
        sentence[i++] = ch;
    }
    sentence[i] = '\0';

    double avg = compute_average_word_length(sentence);
    printf("Average word length: %.1f\n", avg);

    return 0;
}