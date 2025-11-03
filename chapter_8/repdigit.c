#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>

int main()
{
	bool digit_seen[10] = { false };
	int digit;
	long n;

	printf("Enter a number(n=-1,quit):");
	scanf("%ld", &n);

	for (;;)
	{
		if (n == -1)break;
		while (n > 0)
		{
			digit = n % 10;
			if (digit_seen[digit])break;
			digit_seen[digit] = true;
			n /= 10;
		}

		if (n > 0)
			printf("Repeated digit\n");
		else
			printf("No repeated digit\n");

		printf("Enter a number:");
		scanf("%ld", &n);
	}

	return 0;
}