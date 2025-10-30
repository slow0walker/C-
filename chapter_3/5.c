#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int matrix[4][4];
	int row, col;
	int row_sum[4] = { 0 };
	int col_sum[4] = { 0 };
	int diag1_sum = 0, diag2_sum = 0;
	printf("Enter the numbers from 1 to 16 in any order:\n");
	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++)
		{
			scanf("%d ", &matrix[row][col]);
		}
	}

	printf("\n");
	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++)
		{
			printf("%4d", matrix[row][col]);
		}
		printf("\n");
	}

	// 计算每行和
	for (row = 0; row < 4; row++) {
		for (col = 0; col < 4; col++) {
			row_sum[row] += matrix[row][col];
		}
	}
	// 计算每列和
	for (col = 0; col < 4; col++) {
		for (row = 0; row < 4; row++) {
			col_sum[col] += matrix[row][col];
		}
	}
	// 计算两条对角线和（主对角线：行=列；副对角线：行+列=3）
	for (row = 0; row < 4; row++) {
		diag1_sum += matrix[row][row];
		diag2_sum += matrix[row][3 - row];
	}

	// 输出结果
	printf("\nRow sums: ");
	for (row = 0; row < 4; row++) {
		printf("%d ", row_sum[row]);
	}

	printf("\nColumn sums: ");
	for (col = 0; col < 4; col++) {
		printf("%d ", col_sum[col]);
	}

	printf("\nDiagonal sums: %d %d\n", diag1_sum, diag2_sum);



	return 0;
}