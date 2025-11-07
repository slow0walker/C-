#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int read_line(char str[], int n)
{
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
	{
		if (i < n)str[i++] = ch;	
	}
	str[i] = '\0';
	return i;
}

int main()
{
	char str[5] = "";
	read_line(str, 5);
	printf("%s", str);
	return 0;
}