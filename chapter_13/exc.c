#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <ctype.h>

//int read_line(char* str, int n)
//{
//	int ch, i = 0;
//	while ((ch = getchar()) !=  EOF)
//	{
//		if (isspace(ch))continue;
//		if (i < n - 1)
//		{
//			str[i++] = ch;
//			if (isspace(ch))break;
//		}
//	}
//	str[i] = '\0';
//}

//int read_line(char* str, int n)
//{
//	int ch, i = 0;
//	while ((ch = getchar()) !='\n'&& ch!= EOF)
//	{
//		if (i < n - 1)
//		{
//			str[i++] = ch;
//		}
//	}
//	str[i] = '\n';
//}


//void capitalize(char* str)
//{
//	int i = 0;
//	for (i = 0; str[i]!='\0'; i++)
//	{
//		if (!isalpha(str[i]))
//		{
//			continue;
//		}
//		else
//		{
//			str[i] = toupper(str[i]);
//		}
//	}
//	
//}

//void capitalize(char* str)
//{
//	char* p = str;
//	while (*p++)
//	{
//		if (!isalpha(*p))continue;
//		else *p = toupper(*p);
//	}
//}


//void capitalize(char* str)
//{
//	char* p = str;
//	while (*p)  // 循环直到 '\0'
//	{
//		if (isalpha(*p))
//			*p = toupper(*p);
//		p++;  // 手动移动指针
//	}
//}
//
//
//void censor(char *str) {
//    char *p = str;
//    while (*p != '\0') {
//        if (*p == 'f' && *(p + 1) == 'o' && *(p + 2) == 'o') {
//            *p = 'x';
//            *(p + 1) = 'x';
//            *(p + 2) = 'x';
//            p += 3;
//        } else {
//            p++;
//        }
//    }
//}
//
//void get_extension(const char* file_name, char* extension)
//{
//	const char* dot = NULL;
//
//	for (int i = str(file_name) - 1; i >= 0; i--)
//	{
//		if (file_name[i] == '.')
//		{
//			dot = &file_name[i + 1];
//			break;
//		}	
//	}
//	if (dot && *dot)
//	{
//		strcpy(extension, dot);
//	}
//	else
//	{
//		extension = '\0';
//	}
//}
//
//
//void build_index_url(const char* domain, char* index_url) {
//	strcpy(index_url, "http://www.");
//	strcat(index_url, domain);
//	strcat(index_url, "/index.html");
//}

#include <string.h>
bool test_extension(const char* file_name, const char* extension)
{
    const char* dot = strrchr(file_name, '.'); // 找到最后一个 '.'
    if (dot == NULL || *(dot + 1) == '\0')
        return false; // 没有扩展名或 '.' 在末尾

    const char* p = dot + 1;   // 指向扩展名开头
    const char* q = extension; // 指向待比较字符串

    while (*p && *q) {
        if (toupper((unsigned char)*p) != toupper((unsigned char)*q))
            return false;
        p++;
        q++;
    }

    // 若两个字符串同时结束 → 匹配成功
    return *p == '\0' && *q == '\0';
}

void remove_filename(char* url)
{
    char* slash = url + strlen(url); // 指向字符串结尾 '\0'

    while (slash > url && *--slash != '/')
        ;  // 从后往前找最后一个 '/'

    if (slash > url)
        *slash = '\0';  // 用 '\0' 截断字符串
}

int main()
{
	char s[] = "Hsjodi", * p;
	for (p = s; *p; p++)
	{
		--* p;
	}
	puts(s);
	return 0;
}