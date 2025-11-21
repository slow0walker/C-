#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include <stdio.h>

static void print_str(const char* s)
{
	while (*s)
	{
		putchar(*s++);
	}
}

void display(int n, ...)
{
	va_list ap;
	va_start(ap, n);

	for (int i = 0; i < n; i++)
	{
		const char* s = va_arg(ap, const char*);
		printf("%s", s);
		if (i < n - 1)
			putchar(' ');
	}
	putchar('\n');
	va_end(ap);
}

int main()
{
	display(4, "Special", "Agent", "Dale", "Cooper");

	return 0;
}