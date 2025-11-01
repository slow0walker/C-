#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	double epsilon, term = 1.0, e = 1.0;
	int n = 1;
	printf("Enter a small floating-point number ¦Å: ");
	scanf("%lf", &epsilon);

	do {
		term = term / n;
		e += term;
		n++;
	} while (term >= epsilon);
	printf("e ¡Ö %.15lf\n", e);
	return 0;
}