#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char* argv[])
{
	FILE* fp;
	int ch;
	int i;

	if (argc < 2)
	{
		printf("usage: programe...\n");
		exit(EXIT_FAILURE);
	}
	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "cant open %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		while ((ch=fgetc(fp))!=EOF)
		{
			putchar(toupper(ch));
		}
		fclose(fp);
	}
	return 0;
}