#define _CRT_SECURE_NO_WARNINGS 1
#ifndef SAFE_MEMORY_H
#define SAFE_MEMORY_H

#include <stdlib.h>

/* 使用这些宏可以自动附加文件名和行号信息 */
#define MY_MALLOC(size) my_malloc(size, __FILE__, __LINE__)
#define MY_CALLOC(n, size) my_calloc(n, size, __FILE__, __LINE__)
#define MY_REALLOC(ptr, size) my_realloc(ptr, size, __FILE__, __LINE__)
#define MY_FREE(ptr) my_free(ptr, __FILE__, __LINE__)

/* 函数声明 */
void* my_malloc(size_t size, const char* file, int line);
void* my_calloc(size_t num, size_t size, const char* file, int line);
void* my_realloc(void* ptr, size_t size, const char* file, int line);
void  my_free(void* ptr, const char* file, int line);

#endif
