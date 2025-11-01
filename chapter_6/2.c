#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int m, n;
	printf("Enter two integers:");
	scanf("%d %d", &m, &n);

	while (n != 0)
	{
		int temp = m % n;
		m = n;
		n = temp;
	}
	printf("Greatest common divisor: %d", m);
	return 0;
}