#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define SIZE 10
#define DIRECTIONS 4

void generate_random_walk(char grid[][SIZE])
{
	int i, j;
	//1. 初始化网格为'.'
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < SIZE; j++)
		{
			grid[i][j] = '.';
		}
	}
	srand((unsigned int)time(NULL));
	// 2. 定义四个方向：上、下、左、右
	int dirs[DIRECTIONS][2] = { {-1,0},{1,0},{0,-1},{0,1} };//上、下、左、右

	 // 3. 随机起点
	int row = rand() % SIZE;
	int col = rand() % SIZE;
	char ch = 'A';
	grid[row][col] = ch;
	/*int step = 1;*/

	//while (step < 26)
	//{
	//	//下一个随机位置
	//	int dir = rand() % 4;
	//	int new_row = row + dirs[dir][0];
	//	int new_col = col + dirs[dir][1];

	//	//检查是否在网格内且未被访问
	//	if (new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE && grid[new_row][new_col] == '.')
	//	{
	//		row = new_row;
	//		col = new_col;
	//		++ch;
	//		grid[row][col] = ch;
	//		step++;
	//	}
	//}
	// 4. 生成路径
	while (ch < 'Z') {
		int dir = rand() % 4;  // 随机方向
		int new_row = row + dirs[dir][0];
		int new_col = col + dirs[dir][1];

		// 检查是否出界或该位置已访问
		if (new_row >= 0 && new_row < SIZE && new_col >= 0 && new_col < SIZE && grid[new_row][new_col] == '.') {
			++ch;
			grid[new_row][new_col] = ch;
			row = new_row;
			col = new_col;

		}
		else {
			// 检查四个方向都被堵死
			int blocked = 1;//假设一开始是被堵住的
			for (int k = 0; k < DIRECTIONS; k++) {
				int r = row + dirs[k][0];
				int c = col + dirs[k][1];
				if (r >= 0 && r < SIZE && c >= 0 && c < SIZE && grid[r][c] == '.') {
					blocked = 0;  //如果条件成立，说明没有堵住
					break;
				}
			}
			if (blocked) break;  // 如果成立，则无路可走，提前结束
		}
	}
}
void print_array(char walk[][SIZE])
{
	int i, j;
	for (i = 0; i < SIZE; i++) {
		for (j = 0; j < SIZE; j++) {
			printf("%c ", walk[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	char walk[SIZE][SIZE];
	generate_random_walk(walk);
	print_array(walk);
	return 0;
}