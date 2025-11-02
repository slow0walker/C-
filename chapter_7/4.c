#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <ctype.h>

int main()
{
	char ch;
	printf("Enter phone number:");
	while ((ch=getchar())!='\n')
	{
		if (isalpha(ch))
		{
			ch = toupper(ch);
			switch (ch)
			{
			case 'A':case 'B':case 'C':
				putchar('2');
				break;
            case 'D': case 'E': case 'F':
                putchar('3');
                break;
            case 'G': case 'H': case 'I':
                putchar('4');
                break;
            case 'J': case 'K': case 'L':
                putchar('5');
                break;
            case 'M': case 'N': case 'O':
                putchar('6');
                break;
            case 'P': case 'Q': case 'R': case 'S':
                putchar('7');
                break;
            case 'T': case 'U': case 'V':
                putchar('8');
                break;
            case 'W': case 'X': case 'Y': case 'Z':
                putchar('9');
                break;

			default:
				break;
			}
		}
        else
        {
            putchar(ch);
        }

	}
    return 0;
}