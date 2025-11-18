#define _CRT_SECURE_NO_WARNINGS 1
#include <ctype.h>
#include <stdio.h>
#include<stdbool.h>

bool is_identifier(char* str)
{
	if (*str == '\0')return false;
	//检查第一个字符
	if (!(isalnum(*str) || *str == '_'))
		return false;
	str++;
	while (*str != '\0')
	{
		if (!(isalnum(*str) || *str == '_'))
			return false;
		str++;
	}
	return true;
}
int main()
{
	printf("%d\n", is_identifier("abc"));     // 1
	printf("%d\n", is_identifier("_a1"));     // 1
	printf("%d\n", is_identifier("9test"));   // 0
	printf("%d\n", is_identifier("a-b"));     // 0
	printf("%d\n", is_identifier(""));        // 0

	return 0;
}