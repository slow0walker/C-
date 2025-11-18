#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

char* my_strdup(const char* s)
{
	char* p = malloc(strlen(s) + 1);
	if (!p)return NULL;

	memcpy(p, s, strlen(s) + 1);
	return p;
}


int my_stricmp(const char* s1, const char* s2)
{
	unsigned char c1, c2;
	while (*s1&&*s2)
	{
		c1 = tolower((unsigned char)*s1);
		c2 = tolower((unsigned char)*s2);
		if (c1 != c2)
			return c1 - c2;
		s1++;
		s2++;
	}
	return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

char* my_strlwr(char* s)
{
	char* p = s;
	while (*p)
	{
		*p = tolower((unsigned char)*p);
	}
	return s;
}

char* my_strrev(char* s)
{
	char* left = s;
	char* right = s + len(s) - 1;
	char tmp;

	while (left < right)
	{
		tmp = *right;
		*right = *left;
		*left = tmp;
		left++;
		right--;
	}
	return s;
}

char* my_strset(char* s, int ch)
{
	char* p = s;

	while (*p) {
		*p = (char)ch;
		p++;
	}

	return s;
}


#include <string.h>

int count_words(char* sentence)
{
	int count = 0;
	char* token;

	/* strtok 以空白字符集合为分隔符 */
	token = strtok(sentence, " \t\n\r\v\f"); //" \t\n\r\v\f" 是 C 标准中全部的“空白字符”

	while (token != NULL) {
		count++;
		token = strtok(NULL, " \t\n\r\v\f");
	}

	return count;
}

