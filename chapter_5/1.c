#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int num;
	printf("Enter a number:");
	scanf("%d", &num);

	if (num >= 0 && num <= 9)
	{
		printf("The number %d has 1 digit", num);
	}
	else if (num >= 10 && num <= 99)
	{
		printf("The number %d has 2 digit", num);
	}
	else if (num >= 100 && num <= 999)
	{
		printf("The number %d has 3 digit", num);
	}
	return 0;
}