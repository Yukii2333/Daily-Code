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
		for (int j = 0; j < col; j++)//����   |   |   ,
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");

		if (i < row - 1)//ʼ��Ҫ����������һ��
		{
			for (int k = 0; k < row; k++)//����--- --- ---
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
	int r = 0;//�������
	int c = 0;//�������
	printf("player turn��\n");
	while (1)//д1����ѭ����������������ֱ�ӿ�������
	{
		printf("sample: 1 1 ==>1st row,1st col\n");
		printf("	1<=r<=%d 1<=y<=%d\n", row, col);
		scanf("%d %d", &r, &c);
	
		if (r >= 1 && r <= row && c >= 1 && c <= col)
		{
			if (board[r - 1][c - 1] == ' ')
			{
				board[r - 1][c - 1] = '*';//��������-1����Ϊ�����±��0��ʼ
				break;
			}
			else
			{
				printf("��λ�ñ�ռ�����뻻��λ����\n");
			}
		}
		else
		{
			printf("�밴�涨������\n");
		}
	}

}

void pc_turn(char board[ROW][COL], int row, int col)
{
	printf("pc turn:\n");
	while (1)
	{
		int r = rand() % row;//ͨ��rand�������������
		int c = rand() % col;//ͨ��%row��%col���õ���Χ�ڵ���

		if (board[r][c] == ' ')//�ж���������Ƿ�ռ�ã���ռ�þͽ���ѭ��
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

	for(i = 0; i < row; i++)//forѭ���ж����Ƿ�����������
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

	for (i = 0; i < col; i++)//�ж����Ƿ�������
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

	for (i = 0,j = 0; i < row; i++)//�ж����ϵ�����
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

	for (i = 0, j = col - 1; i < row; i++)//�ж����ϵ�����
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
