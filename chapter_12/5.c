#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 1000

// 判断是否为终止字符
bool is_terminator(char c) {
    return c == '.' || c == '?' || c == '!';
}

// 判断是否为空格
bool is_space(char c) {
    return c == ' ';
}

int main() {
    char sentence[MAX_LEN];
    char terminator;
    char* p = sentence;
    char* end = sentence;

    printf("Enter a sentence: ");
    // 读取句子并记录终止字符
    while (true) {
        char ch = getchar();
        if (is_terminator(ch)) {
            terminator = ch;
            break;
        }
        *p++ = ch;
    }
    *p = '\0'; // 字符串结束标记
    end = p - 1; // 指针指向最后一个有效字符

    printf("Reversal of sentence: ");
    while (end >= sentence) {
        // 反向找到单词起始位置
        while (end >= sentence && !is_space(*end)) {
            end--;
        }
        // 打印当前单词
        char* word_start = end + 1;
        while (*word_start != '\0' && !is_space(*word_start)) {
            putchar(*word_start++);
        }
        // 打印空格（非第一个单词时）
        if (end >= sentence) {
            putchar(' ');
        }
        end--;
    }
    // 打印终止字符
    putchar(terminator);
    printf("\n");

    return 0;
}