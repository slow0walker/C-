#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double x;
	printf("Enter the value of x:");
	scanf("%lf", &x);

	double x2 = x * x;
	double x3 = x2 * x;
	double x4 = x3 * x;
	double x5 = x4 * x;
	
	double result = 3 * x5 + 2 * x4 - 5 * x3 - x2 + 7 * x + 6;
	
	printf("value: %.2lf", result);
	return 0;
}