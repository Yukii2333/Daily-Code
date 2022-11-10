#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

int arounded_mine(char mine[ROWS][COLS], int x, int y)
{   //�ַ������ʵ����ASCII�������
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
		system("cls");//������մ��ڣ�����Ϸ�������õ㣨Ӧ�ã�
		print_board(show, ROW, COL);
		printf("������Ҫ�Ų��λ��\n");
		printf("����:��1�е�2��==>1 2\n");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)//�ж���������
		{
			if (mine[x][y] == '1')
			{
				system("cls");
				printf("�㱻ը����\n");
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
					printf("�������!!\n");
				}
			}
		}
		else
		{
			printf("�밴�涨����!\n");
		}
	}
	if (win == (row * col - EASY))
	{
		printf("ͨ����!!\n");
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