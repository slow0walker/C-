#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num;
	printf("Enter a two-digit number:");
	scanf("%d", &num);

	int num1 = num % 10;
	int num2 = num / 10;

	printf("The reversal is: %d%d", num1, num2);
	return 0;
}