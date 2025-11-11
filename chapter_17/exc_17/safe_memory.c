#define _CRT_SECURE_NO_WARNINGS 1
#include "safe_memory.h"
#include <stdio.h>

/* 安全版 malloc */
void* my_malloc(size_t size, const char* file, int line)
{
    void* p = malloc(size);
    if (!p) {
        fprintf(stderr, "[Error] malloc failed at %s:%d (size=%zu bytes)\n",
            file, line, size);
        exit(EXIT_FAILURE);
    }
    return p;
}

/* 安全版 calloc */
void* my_calloc(size_t num, size_t size, const char* file, int line)
{
    void* p = calloc(num, size);
    if (!p) {
        fprintf(stderr, "[Error] calloc failed at %s:%d (num=%zu, size=%zu)\n",
            file, line, num, size);
        exit(EXIT_FAILURE);
    }
    return p;
}

/* 安全版 realloc */
void* my_realloc(void* ptr, size_t size, const char* file, int line)
{
    void* p = realloc(ptr, size);
    if (!p && size != 0) {
        fprintf(stderr, "[Error] realloc failed at %s:%d (size=%zu bytes)\n",
            file, line, size);
        exit(EXIT_FAILURE);
    }
    return p;
}

/* 安全版 free（允许传入 NULL）*/
void my_free(void* ptr, const char* file, int line)
{
    if (ptr == NULL) {
        fprintf(stderr, "[Warning] free(NULL) at %s:%d\n", file, line);
        return;
    }
    free(ptr);
}
