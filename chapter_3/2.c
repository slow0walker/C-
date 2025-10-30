#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()
{
	int item_num;
	float unit_price;
	int mm, dd, yyyy;

	printf("Enter item number:");
	scanf("%d", &item_num);

	printf("Enter unit price:");
	scanf("%f", &unit_price);

	printf("Enter purchase data(mm/dd/yyyy):");
	scanf("%d/%d/%d", &mm, &dd, &yyyy);

	printf("\nItem\t\tUnit\t\tPurchase\n");
	printf("\t\tPrice\t\tDate\n");

	printf("%d\t\t$%7.2f\t%d/%d/%d\n", item_num, unit_price, mm, dd, yyyy);

	return 0;
}