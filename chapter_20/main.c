#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//1
//int main()
//{
//	/*unsigned short i = 8, j = 9;
//	printf("%d", i >> 1 + j >> 1);*/
//	/*unsigned short i = 1;
//	printf("%d", i & ~i);*/
//	unsigned short i = 7,j = 8, k = 9;
//	printf("%d", i ^j &k);
//	return 0;
//}



//3
//#define M(x,y) ((x)^=(y),(y)^=(x),(x)^=(y))
//
//int main()
//{
//	int x, y;
//	scanf("%d %d", &x, &y);
//	printf("%d %d\n", x, y);
//	M(x, y);
//	printf("%d %d\n", x, y);
//	return 0;
//}

//4

//#define MK_COLOR(r,g,b) ((long)((unsigned char)(g)<<16))|(unsigned char)(r)<<8)|(unsigned char)(b)))
//
//#define GET_RED(color) ((unsigned char)(((long)(color)) >> 16))
//#define GET_GREEN(color) ((unsigned char)(((long)(color)) >> 8))
//#define GET_BLUE(color) ((unsigned char)((long)(color)))

//#include <stdio.h>
//
//unsigned short swap_bytes(unsigned short i) {
//    // 高8位右移8位，低8位左移8位，再组合
//    return (i >> 8) | (i << 8);
//}
//
//int main() {
//    unsigned short num;
//    printf("Enter a hexadecimal number (up to four digits): ");
//    scanf("%hx", &num); // %hx 读取16进制unsigned short
//    unsigned short swapped = swap_bytes(num);
//    printf("Number with bytes swapped: %hx\n", swapped);
//    return 0;
//}

//#include <stdio.h>
//
//// 左循环移位
//unsigned int rotate_left(unsigned int i, int n) {
//    if (n < 0 || n >= 32)return 1;
//    return (i << n) | (i >> (32 - n));
//}
//
//// 右循环移位
//unsigned int rotate_right(unsigned int i, int n) {
//    if (n < 0 || n >= 32)return 1;
//    return (i >> n) | (i << (32 - n));
//}

//int count_ones(unsigned char ch)
//{
//	int count;
//	for(int i=0;i<8;i++)
//	{ 
//		count += ch & 1;
//		ch >> 1;
//	}
//	return count;
//}
//
//int count_ones(unsigned char ch) {
//	// 每2位一组求和，再每4位一组，最后每8位一组
//	ch = (ch & 0x55) + ((ch >> 1) & 0x55); // 0x55 = 01010101
//	ch = (ch & 0x33) + ((ch >> 2) & 0x33); // 0x33 = 00110011
//	ch = (ch & 0x0F) + ((ch >> 4) & 0x0F); // 0x0F = 00001111
//	return ch;
//}
//
//unsigned int reverse_bits(unsigned int n) {
//	n = ((n >> 1) & 0x55555555) | ((n << 1) & 0xAAAAAAAA); // 交换相邻1位
//	n = ((n >> 2) & 0x33333333) | ((n << 2) & 0xCCCCCCCC); // 交换相邻2位
//	n = ((n >> 4) & 0x0F0F0F0F) | ((n << 4) & 0xF0F0F0F0); // 交换相邻4位
//	n = ((n >> 8) & 0x00FF00FF) | ((n << 8) & 0xFF00FF00); // 交换相邻8位
//	n = ((n >> 16) & 0x0000FFFF) | ((n << 16) & 0xFFFF0000); // 交换相邻16位
//	return n;
//}
//
//typedef unsigned long DWORD;  // 双字，32位
//typedef unsigned short WORD;  // 字，16位
//
//union regs {
//    struct {
//        WORD ax;    // 低16位（对应AX）
//        WORD eax_hi;// 高16位（EAX的高半部分）
//    } eax;
//    struct {
//        WORD bx;
//        WORD ebx_hi;
//    } ebx;
//    struct {
//        WORD cx;
//        WORD ecx_hi;
//    } ecx;
//    struct {
//        WORD dx;
//        WORD edx_hi;
//    } edx;
//    DWORD eax_full; // 完整EAX（32位）
//    DWORD ebx_full;
//    DWORD ecx_full;
//    DWORD edx_full;
//};


//#include <stdint.h>
//
//
//typedef struct {
//    unsigned int mantissa : 23;  // 小数位（23位）
//    unsigned int exponent : 8;   // 指数位（8位）
//    unsigned int sign : 1;       // 符号位（1位）
//} FloatBits;
//
//union FloatUnion {
//    float f_val;          // 作为float
//    FloatBits bits;       // 作为位结构
//};
//
//int main() {
//    union FloatUnion u;
//    u.bits.sign = 1;       // 符号位1（负）
//    u.bits.exponent = 128; // 指数位128（偏移127，实际指数1）
//    u.bits.mantissa = 0;   // 小数位0（尾数为1.0）
//    printf("%f\n", u.f_val); // 输出-2.0
//    return 0;
//}


int main()
{
	int __Abs__ = 5;
	printf("%d", __Abs__);
	return 0;
}