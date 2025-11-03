#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//int main()
//{
//	int row=5, col=5;
//	int matrix[5][5] = { 0 };
//	for (int i = 0; i < row; i++)
//	{
//		printf("Enter row %d:", i + 1);
//		for (int j = 0; j < col; j++)
//		{
//			scanf("%d", &matrix[i][j]);
//		}
//		printf("\n");
//	}
//
//	int row_sum = 0, col_sum = 0;
//	int r_s[5] = { 0 }, c_s[5] = { 0 };
//
//	for (int i = 0; i < row; i++)
//	{
//		row_sum = 0;
//		for (int j = 0; j < col; j++)
//		{
//			row_sum += matrix[i][j];
//		}
//		r_s[i] = row_sum;
//	}
//
//	for (int j = 0; j < col; j++)
//	{
//		col_sum = 0;
//		for (int i = 0; i < row; i++)
//		{
//			col_sum += matrix[i][j];
//		}
//		c_s[j] = col_sum;
//	}
//
//	printf("Row totals:");
//	for (int i = 0; i < row; i++)
//	{
//		printf("%d ", r_s[i]);
//	}
//
//	printf("\nColumn totals:");
//	for (int i = 0; i <col; i++)
//	{
//		printf("%d ", c_s[i]);
//	}
//
//	return 0;
//}

#define ROWS 5
#define COLS 5

//牛逼哦
//牛逼哦
int main() {
    int arr[ROWS][COLS];
    int row_sum[ROWS] = { 0 };
    int col_sum[COLS] = { 0 };
    int i, j;

    // 读取数组
    for (i = 0; i < ROWS; i++) {
        printf("Enter row %d: ", i + 1);
        for (j = 0; j < COLS; j++) {
            scanf("%d", &arr[i][j]);
            row_sum[i] += arr[i][j];
            col_sum[j] += arr[i][j];
        }
    }

    // 输出每行和
    printf("Row totals: ");
    for (i = 0; i < ROWS; i++) {
        printf("%d ", row_sum[i]);
    }
    printf("\n");

    // 输出每列和
    printf("Column totals: ");
    for (j = 0; j < COLS; j++) {
        printf("%d ", col_sum[j]);
    }
    printf("\n");

    return 0;
}