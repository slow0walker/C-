#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int spilt(int a[], int low, int high);

int main()
{
	int a[N], i;

	printf("Enter %d numbers to be sorted:",N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n");

	quicksort(a, 0, N - 1);

	printf("In sorted order:");
	for (int i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}

void quicksort(int a[], int low, int high)
{
	int middle;

	if (low >= high)return;
	middle = spilt(a, low, high);
	quicksort(a, low, middle - 1);
	quicksort(a, middle + 1, high);
}

int spilt(int a[], int low, int high)
{
	int part_element = a[low];

	for (;;)
	{
		while (low < high && part_element <= a[high])high--;
		if (low >= high)break;
		a[low++] = a[high];

		while (low < high && a[low]<=part_element)low++;
		if (low >= high)break;
		a[high--] = a[low];
	}
	a[high] = part_element;
	return high;
}
