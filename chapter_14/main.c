#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main(void)
//{
//    printf("当前文件名: %s\n", __FILE__);
//    printf("当前行号: %d\n", __LINE__);
//    printf("编译日期: %s\n", __DATE__);
//    printf("编译时间: %s\n", __TIME__);
//    /*printf("是否符合 ANSI C 标准: %d\n", __STDC__);
//    printf("C 标准版本: %ld\n", __STDC_VERSION__);*/
//    printf("当前函数名: %s\n", __func__);
//    return 0;
//}
//#pragma warning(disable:4996) // 禁用“unsafe function”警告
//#include <stdio.h>
//
//int main() {
//    char s[10];
//    gets(s); // 会被警告：不安全函数
//    printf("%s\n", s);
//}

//#include <stdio.h>
//#define  CUBE(x) (x*x*x)
//#define RE(x) ((x)%4)
//#define CH(x,y) ((x*y)<100?1:0)
//
//
//int main()
//{
//	int x=5;
//	int y = 6;
//	printf("cu= %d re= %d ch = %d", CUBE(x), RE(x), CH(x, y));
//	return 0;
//}
//#include<string.h>
//#include <stdio.h>
//
//#include <math.h> 

//#define NELEMS(a) (sizeof(a)/sizeof(a[0]))
//
//#define T(c) ('a'<=(c)&&(c)<='z'?(c)-'a'+'A':(c))




//#define DISP(f,x) (printf(#f"(%g) = %g\n",x,f(x)))
//
//#define DISP2(f,x,y) (printf(#f"(%g,%g) = %g\n",x,y,f(x,y)))
//
//#define GENERIC_MAX(type) type type##_max(type x,type y){return x>y?x:y;}
//
//#define LINE_FILE "Line " #__LINE__ " of file " __FILE__
//
//#define CHECK(x, y, n) ((x) >= 0 && (x) <= (n)-1 && (y) >= 0 && (y) <= (n)-1 ? 1 : 0)
//
//#define CHECK(x, y, n) ((x) >= 0 && (x) <= (n)-1 && (y) >= 0 && (y) <= (n)-1 ? 1 : 0)
//
//#define MEDIAN(x, y, z) ((x) <= (y) ? ((y) <= (z) ? (y) : ((x) <= (z) ? (z) : (x))) : ((x) <= (z) ? (x) : ((y) <= (z) ? (z) : (y))))
//
//#define POLYNOMIAL(x) (3*(x)*(x) + 2*(x)*(x)*(x)*(x) - 5*(x)*(x)*(x) - (x)*(x) + 7*(x) - 6)
//
//int main()
//{
//	double i = 10;
//    DISP(sqrt, i);
//	return 0;
//}

#include <stdio.h>
#define N 100
void f(void);
int main(void)
{
    f();
#ifdef N
#undef N
#endif
    return 0;
}
void f(void)
{
#if defined(N)
    printf("N is %d\n", N);
#else
    printf("N is undefined\n");
#endif
}