#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main(int argc, char* argv[])
{
	FILE* fp;
	bool fail = false; 
	int i;
	if (argc < 2)
	{
		printf("usage: canopen filename...\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{	
			printf("%s can't be opened\n", argv[i]);
			fail = true;
		}
		else
		{
			printf("%s can be opend\n", argv[i]);
			fclose(fp);
		}
	}
	if (fail)
	{
		exit(EXIT_FAILURE);
	}
	return 0;
}