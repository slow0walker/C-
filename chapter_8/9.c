#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define DIRECTIONS 4

int main()
{
	char grid[SIZE][SIZE];
	int i, j;
	// 初始化网格为'.'
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			grid[i][j] = '.';
		}
	}
	srand((unsigned int)time(NULL));

	int dirs[DIRECTIONS][2] = { {-1,0},{1,0},{0,-1},{0,1} };//上、下、左、右
	int row = rand() % SIZE;
	int col = rand() % SIZE;
	char ch = 'A';
	grid[row][col] = ch;
	int step = 1;

	while (step < 26)
	{
		//下一个随机位置
		int dir = rand() % 4;
		int new_row = row + dirs[dir][0];
		int new_col = col + dirs[dir][1];

		//检查是否再网格内且未被访问
		if (new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE && grid[new_row][new_col] == '.')
		{
			row = new_row;
			col = new_col;
			++ch;
			grid[row][col] = ch;
			step++;
		}
		
		
		
	}
	// 打印网格
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%c ", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}