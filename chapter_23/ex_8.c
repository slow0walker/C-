#define _CRT_SECURE_NO_WARNINGS 1
#include <string>
#include <stdio.h>


//函数想统计字符串中某个字符出现的次数，但现在的写法会崩溃，也不能正确计数
//int number(const char* s, char ch)
//{
//	int count = 0;
//	if (*s == '\0')return 0;
//	while (*s)
//	{
//		if (ch == (*strchr(s, ch)))
//			count++;
//		s++;
//	}
//	return count;
//}

int number(const char* s, char ch)
{
	int count = 0;
	const char* p = s;

	while (*p)
	{
		if ((p = strstr(p, ch)) != NULL)
			count++;
		p++;
	}
	return count;
}