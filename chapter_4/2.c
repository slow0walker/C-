#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int num;
	printf("Enter a three-digit number:");
	scanf("%d", &num);

	int num3= num / 100;
	int num2 = num % 100/10;
	int num1 = num % 100 % 10;

	printf("The reversal is: %d%d%d", num1, num2,num3);
	return 0;
}