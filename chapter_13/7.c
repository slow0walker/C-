#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
    // 字符串指针数组存储十位和个位对应的英文单词
    const char* tens[] = { "twenty", "thirty", "forty", "fifty",
                          "sixty", "seventy", "eighty", "ninety" };
    const char* teens[] = { "eleven", "twelve", "thirteen", "fourteen",
                           "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };
    const char* ones[] = { "one", "two", "three", "four", "five",
                          "six", "seven", "eight", "nine" };

    int num;
    printf("Enter a two-digit number: ");
    scanf("%d", &num);

    int ten_digit = num / 10;
    int one_digit = num % 10;

    printf("You entered the number ");
    if (ten_digit == 1) {
        if (one_digit == 0) {
            printf("ten");
        }
        else {
            printf("%s", teens[one_digit - 1]);
        }
    }
    else {
        printf("%s", tens[ten_digit - 2]);
        if (one_digit != 0) {
            printf("-%s", ones[one_digit - 1]);
        }
    }
    printf(".\n");

    return 0;
}