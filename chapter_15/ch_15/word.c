#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include "word.h"
//#include <ctype.h>
int read_char(void)
{
	int ch = getchar();

	if (ch == '\n' || ch == '\t')
	{
		return ' ';
	}
	return ch;
}

int read_word(char* word, int len)
{
	int ch, pos = 0;
	while ((ch = read_char()) == ' ')
		;
	while (ch!=' '&&ch!=EOF)
	{
		if (pos < len)
			word[pos++] = ch;
		ch = read_char();
	}
	word[pos] = '\0';
	return pos;
}

//void read_word1(char* word, int len)
//{
//	int ch, pos=0;
//
//	while ((ch = getchar()) != EOF && isspace(ch))
//		;
//	if (ch == EOF)
//	{
//		word[pos] = '\0';
//		return;
//	}
//	word[pos++] = ch;
//	while ((ch = getchar()) != EOF && !isspace(ch))
//	{
//		if (pos < len)
//			word[pos++] = ch;
//	}
//
//	word[pos] = '\0';
//}