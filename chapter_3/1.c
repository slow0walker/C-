#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int month, day, year;

	printf("Enter a data (mm/dd/yyyy):");
	scanf("%d/%d/%d", &month, &day, &year);

	printf("You entered the data: %d%02d%02d", year, month, day);

	return 0;
}