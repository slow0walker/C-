#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	
	int i, n;
	printf("This program prints a table of squares.\n");
	printf("Enter number of entries in table: ");
	scanf("%d", &n);
	while (n != 0)
	{
		for (i = 1; i <= n; i++)
		{
			printf("%10d%10d\n", i, i * i);
		}
		printf("Enter number of entries in table: ");
		scanf("%d", &n);
	}
	return 0;

}