#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
int sum_array(const int* a, int n)
{
	const int* p;
	int sum = 0;
	p = a;
	while (p < (a + n))
	{
		sum += *p++;
	}
	return sum;
}

bool search(const int* a, int n, int key)
{
	const int* p = a;
	for (p = a; p < a + n; p++)
	{
		if (key == *p)return true;
	}
	return false;
}

void store_zeros(int a[], int n)
{
	int* p = a;
	while (p<&a[n])
	{
		*p++ = 0;
	}
}

double inner_product(const double* a, const double* b, int n)
{
	const double* p, * q;
	double sum = 0.0;
	for (p = a, q = b; p < a + n, q < b + n; p++, q++)
	{
		sum += (*p) * (*q);
	}
	return sum;
}

int find_middle(int a[], int n)
{
	int* p = a;
	return *(p + n / 2);
}

int find_largest(int a[], int n)
{
	int max = a[0];
	int* p;
	for (p = a; p < a + n; p++)
	{
		if (*p > max)
		{
			max = *p;
		}
	}
	return max;
}

void find_two_largest(const int* a, int n, int* largest, int* second_largest)
{
	const int* p;

	if (n < 2)
	{
		*largest = *second_largest = (n > 0) ? a[0] : 0;
	}

	if (a[0] > a[1])
	{
		*largest = a[0];
		*second_largest = a[1];
	}
	else
	{
		*largest = a[1];
		*second_largest = a[0];
	}

	for (p = a; p < a + n; p++)
	{
		if (*p > *largest)
		{
			*second_largest = *largest;
			*largest = *p;
		}
		else if (*p > *second_largest&& *p != *largest)
		{
			*second_largest = *p;
		}
	}


}
#define N 5
void init_ident(int a[N][N])
{
	int* p = &a[0][0];
	for (int i = 0; i < N * N; i++)
	{
		if (i % (N + 1) == 0)
		{
			*p = 1;
		}
		else *p = 0;
		p++;
	}	
}



int main()
{
	int a[5] = { 1,3,2,4,6 };
	int re = 0;
	re=sum_array(a, 5);
	printf("sum = %d", re);
	return 0;

}