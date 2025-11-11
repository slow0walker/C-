#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
void* my_malloc(size_t size)
{
	void* p = malloc(size);
	if (!p)
	{
		fprintf(stderr, "Error: memory allocation failed!\n");
		exit(EXIT_FAILURE);
	}
	else return p;
}