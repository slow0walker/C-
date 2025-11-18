#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char* argv[])
{
	FILE* fp;
	int ch;
	int i;
	bool fail = false;

	if (argc < 2) {
		printf("usage: fcat filename...\n");
		exit(EXIT_FAILURE);
	}

	for (i = 1; i < argc; i++)
	{
		if ((fp = fopen(argv[i], "r")) == NULL)
		{
			fprintf(stderr, "Can't open %s\n", argv[i]);
			fail = true;
			continue;
		}
		while ((ch = fgetc(fp)) != EOF)
		{
			putchar(ch);
		}
		fclose(fp);
	}
	if (fail)
	{
		exit(EXIT_SUCCESS);
	}
	return 0;
}