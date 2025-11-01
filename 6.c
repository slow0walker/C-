#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num;
	printf("Enter an integer:");
	scanf("%d", &num);
	int i = 2;
	while (i <= num)
	{
		printf("%d\n", i * i);
		i += 2;
	}
	return 0;
}