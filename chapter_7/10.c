#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	int count = 0;
	printf("Enter a sentence: ");
	while((ch = getchar()) != '\n')
    {
        ch = tolower(ch);
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            count++;
        }
    }
    printf("Your sentence contains %d vowels.\n", count);
    return 0;
}