#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

#define MAX_DIGITS 10

// 每个数字的七段显示定义
const int segments[10][7] = {
    {1,1,1,1,1,1,0},  // 0
    {0,1,1,0,0,0,0},  // 1
    {1,1,0,1,1,0,1},  // 2
    {1,1,1,1,0,0,1},  // 3
    {0,1,1,0,0,1,1},  // 4
    {1,0,1,1,0,1,1},  // 5
    {1,0,1,1,1,1,1},  // 6
    {1,1,1,0,0,0,0},  // 7
    {1,1,1,1,1,1,1},  // 8
    {1,1,1,1,0,1,1}   // 9
};

char digits[3][MAX_DIGITS * 4];

void clear_digits_array(void)
{
    for (int r = 0; r < 3; r++)
    {
        for (int c = 0; c < MAX_DIGITS * 4; c++)
        {
            digits[r][c] = ' ';
        }
    }
}

void process_digit(int digit, int position)
{
    int offset = position * 4;
    const int* seg = segments[digit];

    // 七段编号:
    //  0
    // 5 1
    //  6
    // 4 2
    //  3
    if (seg[0]) digits[0][offset + 1] = '_';
    if (seg[1]) digits[1][offset + 2] = '|';
    if (seg[2]) digits[2][offset + 2] = '|';
    if (seg[3]) digits[2][offset + 1] = '_';
    if (seg[4]) digits[2][offset + 0] = '|';
    if (seg[5]) digits[1][offset + 0] = '|';
    if (seg[6]) digits[1][offset + 1] = '_';
}
// 打印整个显示数组
void print_digits_array(void)
{
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < MAX_DIGITS * 4; c++)
            putchar(digits[r][c]);
        putchar('\n');
    }
}

int main(void)
{
    char ch;
    int pos = 0;

    clear_digits_array();

    printf("Enter a number: ");
    while ((ch = getchar()) != '\n' && pos < MAX_DIGITS) {
        if (isdigit(ch)) {
            process_digit(ch - '0', pos);
            pos++;
        }
        // 其他字符（如 -、空格、逗号）直接跳过
    }

    print_digits_array();
    return 0;
}