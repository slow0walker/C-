#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include "line.h"

#define MAX_LINE_LEN 60  //目标行宽（每行应为该宽度，在 write_line 时通过插空调节达到）

char line[MAX_LINE_LEN + 1]; //当前行的缓冲区（以 \0 结尾）
int line_len = 0;  //当前 line 的已使用字符数（不含终止 \0
int num_words = 0;   //当前行中已有单词数量（add_word 每次增加）

void clear_line(void)
{	line[0] = '\0';
    line_len = 0;
    num_words = 0;
}

void add_word(const char* word)
{
    if (num_words > 0)
    {
        line[line_len] = ' ';  
        line[line_len + 1] = '\0';
        line_len++; 
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}
int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}

void write_line(void)
{
    int extra_spaces, spaces_to_insert, i, j;
    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++)
    {
        if (line[i] != ' ')
        {
            putchar(line[i]);
        }
        else
        {
            spaces_to_insert = extra_spaces / (num_words - 1);  
            for (j = 0; j <= spaces_to_insert + 1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_insert;
            num_words--;
        }
    }
    putchar('\n');
}

void flush_line(void)
{
    if (line_len > 0)
        puts(line);
}