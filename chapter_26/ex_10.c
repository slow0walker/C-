#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>


//这些函数没有错误检查，所以推荐改用 strtol / strtoll。
//int    atoi(const char* str);
//long   atol(const char* str);
//long long atoll(const char* str);


int my_atoi(const char* str)
{
    return (int)strtol(str, NULL, 10);
}

long my_atol(const char* str)
{
    return strtol(str, NULL, 10);
}

long long my_atoll(const char* str)
{
    return strtoll(str, NULL, 10);
}
