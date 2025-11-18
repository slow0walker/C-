#define _CRT_SECURE_NO_WARNINGS 1
#include <ctype.h>
#include <stdio.h>
#include<stdbool.h>

long int hex_to_long(char* str)
{
	if (*str == '\0')return -1;

	long int value = 0;

	while (*str)
	{
		unsigned char ch = (unsigned char)(*str);
		if (!(isxdigit(ch)))return -1;

		value *= 16;
		if (isdigit(ch))
			value += ch - '0';
		else if (ch >= 'A' && ch <= 'F')
			value += ch - 'A' + 10;
		else
			value += ch - 'a' + 10;
		str++;
	}
	return value;
}
#include <stdio.h>

int main()
{
	printf("%ld\n", hex_to_long("1A3F"));   // 6719
	printf("%ld\n", hex_to_long("ff"));     // 255
	printf("%ld\n", hex_to_long("0"));      // 0
	printf("%ld\n", hex_to_long("3G2"));    // -1 (G 非十六进制)
	printf("%ld\n", hex_to_long(""));       // -1
	return 0;
}
