#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <errno.h>

double try_math_fcn(double (*fcn)(double), double x, const char* str)
{
	errno = 0;
	double re = fcn(x);
	if (errno != 0)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	return re;

}

int main(void)
{
	double x = 9.0;
	double y;

	y = try_math_fcn(sqrt, x, "Error in call of sqrt"); 
	printf("sqrt(%g) = %g\n", x, y);

	return 0;
}
