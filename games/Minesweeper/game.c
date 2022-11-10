#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int arounded_mine(char mine[ROWS][COLS], int x, int y)
{   //字符运算的实质是ASCII码的运算
	return ((mine[x - 1][y - 1] + mine[x - 1][y] + mine[x - 1][y + 1]
		+ mine[x][y - 1] + mine[x][y + 1] + mine[x + 1][y - 1]
		+ mine[x + 1][y] + mine[x + 1][y + 1]) - '0' * 8);
}

void sweep_mine(char show[ROWS][COLS], char mine[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win < (row * col - EASY))
	{
		system("cls");//用来清空窗口，让游戏看起来好点（应该）
		print_board(show, ROW, COL);
		printf("请输入要排查的位置\n");
		printf("例如:第1行第2列==>1 2\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//判断输入坐标
		{
			if (mine[x][y] == '1')
			{
				system("cls");
				printf("你被炸死了\n");
				print_board(mine, ROW, COL);
				break;
			}
			else
			{
				if (show[x][y] == '*')
				{
					system("cls");
					int n = arounded_mine(mine, x, y);
					show[x][y] = n + '0';
					win++;
				}
				else
				{
					system("cls");
					printf("输入过辣!!\n");
				}
			}
		}
		else
		{
			printf("请按规定输入!\n");
		}
	}
	if (win == (row * col - EASY))
	{
		printf("通关辣!!\n");
	}
}

void set_mine(char mine[ROWS][COLS], int row, int col)
{
	int count = EASY;
	while (count)
	{
		int x = (rand() % row+1);
		int y = (rand() % col+1);
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}

void print_board(char board[ROWS][COLS], int row, int col)
{
	for (int j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (int i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (int j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}

void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			board[i][j] = set;	
		}
	}
}