#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include<stdio.h>

int max_int(int n, ...)
{
	va_list ap;
	int current, largest;

	largest = n;
	va_start(ap, n);

	while ((current = va_arg(ap, int)) != 0)
	{
		if (current > largest)largest = current;
	}
	va_end(ap);
	return largest;
}


int main(void)
{
	printf("%d\n", max_int(10, 30, 20, 99, 0));   // 输出 99
	printf("%d\n", max_int(-5, -10, -3, -8, 0));  // 输出 -3
	printf("%d\n", max_int(7, 0));                // 只有一个参数，输出 7

	return 0;
}
