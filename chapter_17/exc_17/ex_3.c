#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
int* create_array(int n, int initial_value)
{
	int* p = (int*)malloc(n * sizeof(int));
	if (!p)
	{
		fprintf(stderr, "Error: memory allocation failed!\n");
		return NULL;
	}
	for (int i = 0; i < n; i++)
	{
		*(p + i) = initial_value;
	}
	return p;
}