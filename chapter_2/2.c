#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define PI 3.14159
#define D 4.0f/3.0f
int main()
{
	float r = 10;
	float volume = D * PI * r * r * r;
	printf("volume = %.2f", volume);
	return 0;
}

