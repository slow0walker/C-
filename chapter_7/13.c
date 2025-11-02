#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	char ch;
	int word_count = 0, letter_count = 0;
	printf("Enter a sentence: ");
	while ((ch = getchar()) != '\n')
	{
		if (ch != ' ')
		{
			++letter_count;
		}
		else
		{
			++word_count;
		}
	}
	++word_count;
	double avg = (double)letter_count / word_count;
	printf("Average word length: %.1f\n", avg);
	return 0;
}