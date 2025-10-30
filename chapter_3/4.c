#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int num1, num2, num3;
	printf("Enter phone number [(xxx) xxx-xxxx]:");
	scanf_s("(%d) %d-%d",&num1,&num2,&num3);
	printf("You entered %d.%d.%d", num1, num2, num3);

	return 0;
}