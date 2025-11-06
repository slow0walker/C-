#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define N 100

int main()
{
	//a
	/*char s[N] = "";
	int i=0;
	char ch;
	while ((ch = getchar()) != '\n' && i < N - 1)
	{
		s[i++] = ch;
	}
	s[i] = '\0';

	for (i = N - 1; i >= 0; i--)
	{
		putchar(s[i]);
	}*/

	//b

	/*char s[N] = "";
	int* p = s;
	while ((*p = getchar()) != '\n' && p < s + N-1)
	{
		p++;
	}
	*p = '\0';
	for (int i = N - 1; i >= 0; i--)
	{
		putchar(s[i]);
	}
	return 0;*/

	char msg[N];
	char ch;
	char* p = msg; // 指针跟踪数组当前位置

	printf("Enter a message: ");
	// 读取字符存入数组，遇换行或数组满时停止
	while ((ch = getchar()) != '\n' && p < msg + N - 1) {
		*p++ = ch;
	}
	*p = '\0'; // 字符串结束标记
	p--; // 指针回退到最后一个有效字符

	printf("Reversal is: ");
	// 逆序打印（指针从后向前遍历）
	while (p >= msg) {
		putchar(*p--);
	}
	printf("\n");

	return 0;
}