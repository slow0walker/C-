#define _CRT_SECURE_NO_WARNINGS 1
#include <stdarg.h>
#include <stdio.h>
#include<limits.h>

char* max_pair(int num_pairs, ...)
{
	va_list ap;
	va_start(ap, num_pairs);

	int max_val = INT_MIN;
	char* max_str = NULL;

	for (int i = 0; i < num_pairs; i++)
	{
		int n = va_arg(ap, int);
		char* s = va_arg(ap, char* );
		if (n > max_val)
		{
			max_val = n;
			max_str = s;
		}
	}
	va_end(ap);
	return max_str;
}
int main()
{
	char* result = max_pair(
		5,
		180, "Seinfeld",
		180, "I Love Lucy",
		39, "The Honeymooners",
		210, "All in the Family",
		86, "The Sopranos"
	);
	printf("%s\n", result);

	return 0;
}