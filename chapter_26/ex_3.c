#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include <stdio.h>

static void print_int(int n)
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

static void print_str(const char* s)
{
	while (*s)
	{
		putchar(*s++);
	}
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
			print_int(va_arg(ap, int));
		}
		else if (*fmt == 's')
		{
			print_str(va_arg(ap, char*));
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
	mini_printf("name=%s, age=%d\n", "Tom", -18);
	return 0;
}