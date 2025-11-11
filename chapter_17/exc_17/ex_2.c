#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void* duplicate(char* str)
{
	size_t len = strlen(str);
	void* p = malloc(len + 1);
	if (!p)
	{
		fprintf(stderr, "Error: memory allocation failed!\n");
		return NULL;
	}
	strcpy(p, str);  // 复制字符串内容
	return p;
}

//安全增强版
char* duplicate(const char* str)
{
    if (str == NULL) return NULL;

    size_t len = strlen(str);
    char* p = malloc(len + 1);
    if (!p)
    {
        fprintf(stderr, "Error: memory allocation failed!\n");
        return NULL;
    }

    memcpy(p, str, len + 1); // 复制包括 '\0'
    return p;
}
