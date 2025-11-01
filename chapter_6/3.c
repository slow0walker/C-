#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int gcd_euclid(int m, int n)
{
	while (n != 0)
	{
		int temp = m % n;
		m = n;
		n = temp;
	}
	return m;
}

int main()
{
	int d1, d2;
	printf("Enter a fraction:");
	scanf("%d/%d", &d1, &d2);

	if (d2 == 0)
	{
		printf(" Error: denominator cannot be zero!");
		return 1;
	}
	int gcd = gcd_euclid(d1, d2);

	printf("In lowest terms: %d/%d", d1/gcd, d2 / gcd);

	return 0;
}