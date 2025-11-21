#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include <stdio.h>

static print_int(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n >= 10)
		print_int(n / 10);
	putchar((n % 10) + '0');
}

void mini_printf(const char* fmt, ...)
{
	va_list ap;
	va_start(ap, fmt);
	for (; *fmt != '\0'; fmt++)
	{
		if (*fmt != '%')
		{
			putchar(*fmt);
			continue;
		}
		fmt++;
		if (*fmt == 'd')
		{
			int val = va_arg(ap, int);
			print_int(val);

		}
		else
		{
			continue;
		}
	}
	
	va_end(ap);
}
int main()
{
	mini_printf("a=%d, b=%d\n", 10, 20);
	return 0;
}