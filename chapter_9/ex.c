#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdbool.h>
//int check(int x, int y, int n)
//{
//	if (x >= 0 && x <= n - 1)
//	{
//		if (y >= 0 && y <= n - 1)
//			return 1;
//		else
//		{
//			return 0;
//		}
//	}
//	else
//		return 0;
//}
//int gcd(int m, int n)
//{
//	int temp;
//	while (temp = m % n)
//	{
//		m = n;
//		n = temp;
//	}
//	return m;
//}
// 判断是否为闰年
bool is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int day_of_year(int month, int day, int year)
{
	int days_in_month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int day_count = day;
	for (int i = 0; i < month - 1; i++)
	{
		day_count += days_in_month[i];
	}
	if (is_leap_year(year) && month > 2)day_count++;

	return day_count;
}

int num_digits(unsigned long n)
{
	int count;
	while (n>0)
	{
		n /= 10;
		count++;
	}
	return count;
}

int digit(int n, int k)
{
	if (k == 0)return 0;

	int count = 1;
	while (count < k && n !=0)
		
	{
		n /= 10;
		count++;
	}
	return n == 0 ? 0 : n % 10;
}
// (a) 返回数组中最大的元素
int max_element(int a[], int n) {
	if (n <= 0) return 0; //这种情况判断是必须的，要考虑完备性，所有的可能性
	int max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

// (b) 返回数组所有元素的平均值
double average(int a[], int n) {
	if (n <= 0) return 0.0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	return (double)sum / n;
}

// (c) 返回数组中正数元素的数量
int positive_count(int a[], int n) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			count++;
		}
	}
	return count;
}

float compute_GPA(char grades[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		char grade = toupper(grades[i]);
		switch (grade) {
		case 'A': sum += 4; break;
		case 'B': sum += 3; break;
		case 'C': sum += 2; break;
		case 'D': sum += 1; break;
		case 'F': sum += 0; break;
		default: break; 
		}
	}
	return (float)sum / n;
}

double inner_product(double a[], double b[], int n) {
	double product = 0.0;
	for (int i = 0; i < n; i++) {
		product += a[i] * b[i];
	}
	return product;
}


int evaluate_position(char board[8][8]) {
	// 定义棋子分值：白棋大写，黑棋小写
	int white_values['R' + 1] = { 0 };
	white_values['K'] = 0; white_values['Q'] = 9; white_values['R'] = 5;
	white_values['B'] = 3; white_values['N'] = 3; white_values['P'] = 1;

	int black_values['r' + 1] = { 0 };
	black_values['k'] = 0; black_values['q'] = 9; black_values['r'] = 5;
	black_values['b'] = 3; black_values['n'] = 3; black_values['p'] = 1;

	int white_sum = 0, black_sum = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			char piece = board[i][j];
			if (isupper(piece)) {
				white_sum += white_values[piece];
			}
			else if (islower(piece)) {
				black_sum += black_values[piece];
			}
		}
	}
	return white_sum - black_sum;
}






int main()
{
	
	return 0;
}