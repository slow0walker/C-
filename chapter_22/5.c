#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#define key '&'

int main(int argc,char *argv[])
{
	FILE* in_fp, * out_fp;
	int orig_ch, new_ch;

	if (argc != 3)
	{
		fprintf(stderr, "usage: %s input_file output_file\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((in_fp = fopen(argv[1], "rb")) == NULL)
	{
		fprintf(stderr,"Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	if ((out_fp = fopen(argv[2],"wb")) == NULL)
	{
		fprintf(stderr, "Can't open %s\n", argv[2]);
		fclose(in_fp);
		exit(EXIT_FAILURE);
	}

	while ((orig_ch = fgetc(in_fp)) != EOF)
	{
		new_ch = orig_ch & key;
		fputc(new_ch, out_fp);
	}

	fclose(in_fp);
	fclose(out_fp);
	return 0;
}