#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int h, s;
	printf("Enter a 24-hour time:");
	scanf("%d:%d", &h, &s);
	if (h >= 0 && h < 12)
	{
		printf("Equivalent 12-hour time: %d:%d a.m", h, s);
	}
	else if (h == 12)
	{
		printf("Equivalent 12-hour time: %d:%d noon", h, s);
	}
	else if(h>12&&h<=24)
	{
		printf("Equivalent 12-hour time: %d:%d p.m", h-12, s);
	}
	return 0;
}