#define _CRT_SECURE_NO_WARNINGS 1
#include<math.h>
#include<stdio.h>

double evaluate_polynomial(double a[], int n, double x)
{
	double sum=a[n];
	for (int i = n-1; i >=0; i--)
	{
		sum = fma(sum, x, a[i]);
	}
	return sum;
}

int main()
{
	double x = 3;
	double a[3] = { 5,2,3 };
	double sum = evaluate_polynomial(a, 2, 3);
	printf("%g", sum);
	return 0;
}