#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include<stdio.h>

char* vstrcat(const char* first, ...)
{
	if (first == NULL)return NULL;

	va_list ap;
	const char* p;
	int total_len = 0;

	//计算需要分配的内存
	va_start(ap, first);
	p = first;
	while (p!=NULL)
	{
		total_len += strlen(p);
		p = va_arg(ap, const char*);
	}
	va_end(ap);

	//动态分配
	char* re = (char *)malloc(total_len + 1);
	if (!re)return NULL;

	p = first;
	char* dst = re;
	va_start(ap, first);
	while (p!=NULL)
	{
		size_t len = strlen(p);
		memcpy(dst, p, len);
		dst += len;
		p = va_arg(ap, const char*);
	}
	va_end(ap);

	*dst = '\0';
	return re;
}

int main()
{
	char* s = vstrcat("Hello ", "world", "! ", "Wonderful C", (char*)0);
	printf("%s\n", s);
	free(s);
	return 0;
}