#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	float num, max = 0.f;

	printf("Enter a number:");
	scanf("%f", &num);

	while (num > 0)
	{
		max = num;
		printf("Enter a number:");
		scanf("%f", &num);
		if (num > max)max = num;
	}

	printf("The largest number entered was %g\n", max);
	return 0;

}