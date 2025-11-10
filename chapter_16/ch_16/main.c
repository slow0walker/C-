#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//// 定义结构体 Complex
//typedef struct c {
//    double real;      // 实部
//    double imaginary; // 虚部
//}Complex;
//
//struct c add(struct c a, struct c b)
//{
//    struct c result;
//    result.real = a.real + b.real;
//    result.imaginary = a.imaginary + b.imaginary;
//    return result;
//}
//
//struct c make_conplex(double real, double imaginary)
//{
//    struct c p;
//    p.real = real;
//    p.imaginary = imaginary;
//}
//
//int main()
//{
//    struct c c1, c2, c3;
//
//    c1.real = 0.0;
//    c1.imaginary = 1.0;
//    c2.real = 1.0;
//    c2.imaginary = 0.0;
// 
//    /*c3.real = c1.real + c2.real;
//    c3.imaginary = c1.imaginary + c2.imaginary;*/
//    /*c3 = (struct c){ c1.real + c2.real, c1.imaginary + c2.imaginary };*/
//    c3 = add(c1, c2);
//    printf("%.1lf %.1lf", c3.real, c3.imaginary);
//    return 0;
//}

struct date { int month; int day;int year };

int day_of_year(struct date d)
{
    // 各月天数（非闰年）
    int days_in_month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int total = 0;
    int i;
    // 判断闰年（二月加1天）
    if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0)) {
        days_in_month[1] = 29;
    }
    // 累加前几个月的天数
    for (i = 0; i < d.month - 1; i++) {
        total += days_in_month[i];
    }
    // 加当月天数
    total += d.day;
    return total;
}
int compare_dates(struct date d1, struct date d2) {
    // 先比较年份
    if (d1.year > d2.year) return 1;
    if (d1.year < d2.year) return -1;
    // 年份相同，比较月份
    if (d1.month > d2.month) return 1;
    if (d1.month < d2.month) return -1;
    // 月份相同，比较日期
    if (d1.day > d2.day) return 1;
    if (d1.day < d2.day) return -1;
    // 日期完全相同
    return 0;
}

struct time {
    int hours;
    int minutes;
    int seconds;
};
struct time split_time(long total_seconds) {
    struct time t;
    // 计算小时（总秒数 ÷ 3600）
    t.hours = total_seconds / 3600;
    // 剩余秒数（总秒数 % 3600）
    total_seconds %= 3600;
    // 计算分钟（剩余秒数 ÷ 60）
    t.minutes = total_seconds / 60;
    // 剩余秒数即为秒
    t.seconds = total_seconds % 60;
    return t;
}

struct fraction {
    int numerator;   
    int denominator; 
};

int gcd(int a, int b) {
    a = a < 0 ? -a : a; // 取绝对值
    b = b < 0 ? -b : b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct fraction simplify(struct fraction f) {
    int g = gcd(f.numerator, f.denominator);
    f.numerator /= g;
    f.denominator /= g;
    // 保证分母为正
    if (f.denominator < 0) {
        f.numerator *= -1;
        f.denominator *= -1;
    }
    return f;
}

struct fraction add_fractions(struct fraction f1, struct fraction f2) {
    struct fraction res;
    res.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    res.denominator = f1.denominator * f2.denominator;
    return simplify(res);
}

struct fraction subtract_fractions(struct fraction f1, struct fraction f2) {
    struct fraction res;
    res.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    res.denominator = f1.denominator * f2.denominator;
    return simplify(res);
}

struct fraction multiply_fractions(struct fraction f1, struct fraction f2) {
    struct fraction res;
    res.numerator = f1.numerator * f2.numerator;
    res.denominator = f1.denominator * f2.denominator;
    return simplify(res);
}

struct fraction divide_fractions(struct fraction f1, struct fraction f2) {
    struct fraction res;
    res.numerator = f1.numerator * f2.denominator;
    res.denominator = f1.denominator * f2.numerator;
    return simplify(res);
}

struct color {
    int red;
    int green;
    int blue;
};



int main()
{
    const struct color MAGENTA_0 ={255,0,255};
    const struct color MAGENTA_1 = { .red=255,.blue=255, };

    return 0;
}