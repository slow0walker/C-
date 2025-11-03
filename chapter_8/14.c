#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100

int main(void)
{
    char sentence[MAX_LEN];
    char ch, end_char;
    int i = 0;
    //读取字符
    printf("Enter a sentence: ");
    while ((ch = getchar()) != '.' && ch != '?' && ch != '!' && i< MAX_LEN-1)
    {
        sentence[i++] = ch;
    }
    sentence[i] = '\0';
    end_char = ch;


    printf("Reversal of sentence: ");
    //i = sizeof(sentence)/sizeof(sentence[0])- 1;sizeof(sentence)/sizeof(sentence[0]) 固定是 100，表示数组长度（即 100 个字符），
    //但输入的实际字符串可能只有比如 12 个字符。
    i = strlen(sentence) - 1;
    while (i >= 0)
    {
        while (i >= 0 && isspace(sentence[i]))
        {
            i--;
        }
        int k = i;
        while (i >= 0 && !isspace(sentence[i]))
        {
            i--;
        }
        int start = i + 1;
        for (int j=start; j <= k;j++)
        {
            putchar(sentence[j]);
        }
        if (i > 0)putchar(' ');
    }
    putchar(end_char);
    putchar('\n');
    return 0;
}

