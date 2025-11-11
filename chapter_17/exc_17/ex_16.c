#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int f(int i);

int sum(int (*f)(int), int start, int end)
{
	int re = 0;
	for (int i = start; i < end; i++)
	{
		re += (*f)(i);
	}
	return re;
}
int f(int i)
{
	return i * i;
}

int main()
{
	
	int re = sum(f, 1, 5);
	printf("re= %d\n", re);
	return 0;
}