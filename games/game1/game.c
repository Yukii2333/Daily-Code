#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

static void Init(int* count, int* count1, int* count2)
{
	*count = 0;
	*count1 = 0;
	*count2 = 0;
}

void init_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void print_board(char board[ROW][COL], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)//棋盘   |   |   ,
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1)//始终要比棋盘行少一行
		{
			for (int k = 0; k < row; k++)//棋盘--- --- ---
			{
				printf("---");
				printf(" ");
			}
		}
		printf("\n");
	}
}

void player_turn(char board[ROW][COL], int row, int col)
{
	int r = 0;//输入的行
	int c = 0;//输入的列
	printf("player turn：\n");
	while (1)//写1是死循环，但是满足条件直接可以跳出
	{
		printf("sample: 1 1 ==>1st row,1st col\n");
		printf("	1<=r<=%d 1<=y<=%d\n", row, col);
		scanf("%d %d", &r, &c);
	
		if (r >= 1 && r <= row && c >= 1 && c <= col)
		{
			if (board[r - 1][c - 1] == ' ')
			{
				board[r - 1][c - 1] = '*';//输入坐标-1，因为数组下标从0开始
				break;
			}
			else
			{
				printf("该位置被占了捏，请换个位置喵\n");
			}
		}
		else
		{
			printf("请按规定输入喵\n");
		}
	}

}

void pc_turn(char board[ROW][COL], int row, int col)
{
	printf("pc turn:\n");
	while (1)
	{
		int r = rand() % row;//通过rand（）生成随机数
		int c = rand() % col;//通过%row或%col来得到范围内的数

		if (board[r][c] == ' ')//判断随机坐标是否被占用，被占用就进入循环
		{
			board[r][c] = '#';
			break;
		}
	}
}

char is_win(char board[ROW][COL], int row, int col)
{
	int count = 0;
	int count1 = 0;
	int count2 = 0;
	int i = 0;
	int j = 0;

	for(i = 0; i < row; i++)//for循环判断行是否有满三个的
	{
		for(j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
			{
				count1++;
			}
			if (board[i][j] == '#')
			{
				count2++;
			}
			count++;
		}
		if (count == row && count1 == row)
		{
			return '*';
		}
		if (count == row && count2 == row)
		{
			return '#';
		}
		if (count == row && count1 != row && count2 != row)
		{
			Init(&count, &count1, &count2);
		}
	}

	Init(&count, &count1, &count2);

	for (i = 0; i < col; i++)//判断列是否满三个
	{
		for (j = 0; j < row; j++)
		{
			if (board[j][i] == '*')
			{
				count1++;
			}
			if (board[j][i] == '#')
			{
				count2++;
			}
			count++;
		}
		if (count == row && count1 == row)
		{
			return '*';
		}
		if (count == row && count2 == row)
		{
			return '#';
		}
		if (count == row && count1 != row && count2 != row)
		{
			Init(&count, &count1, &count2);
		}
	}

	Init(&count, &count1, &count2);

	for (i = 0,j = 0; i < row; i++)//判断左上到右下
	{
		if (board[i][j] == '*')
		{
			count1++;
		}
		if (board[i][j] == '#')
		{
			count2++;
		}
		count++;
		j++;
		if (count == row && count1 == row)
		{
			return '*';
		}
		if (count == row && count2 == row)
		{
			return '#';
		}
		if (count == row && count1 != row && count2 != row)
		{
			Init(&count, &count1, &count2);
		}
	}

	Init(&count, &count1, &count2);

	for (i = 0, j = col - 1; i < row; i++)//判断右上到左下
	{
		if (board[i][j] == '*')
		{
			count1++;
		}
		if (board[i][j] == '#')
		{
			count2++;
		}
		count++;
		j--;
		if (count == row && count1 == row)
		{
			return '*';
		}
		if (count == row && count2 == row)
		{
			return '#';
		}
		if (count == row && count1 != row && count2 != row)
		{
			Init(&count, &count1, &count2);
		}
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
			{
				return 'c';
			}
		}
	}
	
	return 'e';
}
