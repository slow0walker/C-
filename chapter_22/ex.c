#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<stdlib.h>

//void f(void)
//{
//	FILE* fb;
//	if ((fb = fopen("filename", "r")) == NULL)
//	{
//		exit(1);
//	}
//	//¥¶¿Ì
//	fclose(fb);
//}
//int main()
//{
//	int i, j;
//	float x;
//	int n = scanf("%d%f%d", &i, &x, &j);
//	printf("%d %f %d\n", i, x, j);
//	printf("%d", n);
//	return 0;
//}

//10
//while ((ch = getc(source_fp)) != EOF) {
//    if (putc(ch, dest_fp) == EOF) {
//        fprintf(stderr, "Error writing to %s\n", argv[2]);
//        fclose(source_fp);
//        fclose(dest_fp);
//        exit(EXIT_FAILURE);
//    }
//}

int line_length(const char* filename, int n)
{
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
	{
		return 0;
	}
	int current_line = 1;
	int length;
	int ch;
	while ((ch = fgetc(fp))!= EOF)
	{
		if (current_line == n)
		{
			length++;
		}
		if (ch == '\n') {
			current_line++;
		}
	}
	fclose(fp);
	if (current_line < n) 
	{
		return 0;
	}
	return length;
}


char* my_fgets(char* s, int size, FILE* stream) {
	if (s == NULL || size <= 0 || stream == NULL) {
		return NULL;
	}
	int i = 0;
	int ch;
	while (i < size - 1) {
		ch = fgetc(stream);
		if (ch == EOF) {
			if (i == 0) {
				return NULL;
			}
			else {
				break;
			}
		}
		s[i] = (char)ch;
		i++;
		if (ch == '\n') {
			break;
		}
	}
	s[i] = '\0';
	return s;
}

int my_fputs(const char* s, FILE* stream) {
	if (s == NULL || stream == NULL) {
		return EOF;
	}
	int i = 0;
	while (s[i] != '\0') {
		if (fputc(s[i], stream) == EOF) {
			return EOF;
		}
		i++;
	}
	return 0;
}