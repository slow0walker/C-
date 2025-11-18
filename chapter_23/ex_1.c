#define _CRT_SECURE_NO_WARNINGS 1
#include<math.h>
#include<stdio.h>
double round_nearest(double num, int n)
{
	double num_new = num * pow(10, n);
	double num_mid = num_new < 0.0 ? ceil(num_new - 0.5) : floor(num_new+0.5);
	return num_mid / pow(10, n);
}

int main()
{
	double num = 0.0;
	scanf("%lf", &num);
	printf("%g", round_nearest(num, 3));
	return 0;
}