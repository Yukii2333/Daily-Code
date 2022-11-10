#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()//�˵�
{
	printf("**************************************\n");
	printf("**********   Minesweeper   ***********\n");
	printf("************   1. Play   *************\n");
	printf("************   0. Exit   *************\n");
	printf("**************************************\n");
}

void game()
{
	srand((unsigned int)time(NULL));//�����ϵ�1��ʾ��
	char mine[ROWS][COLS] = { 0 };  //�����׵�����
	char show[ROWS][COLS] = { 0 };  //չʾ����ҵ�����
								      //ͨ��0��*�����������̷ֱ��ʼ��
	init_board(mine, ROWS, COLS, '0');//��ʼ������
	init_board(show, ROWS, COLS, '*');//��ʼ����������
	set_mine(mine, ROW, COL);//���õ���
	//print_board(mine, ROW, COL);
	//print_board(show, ROW, COL);//��ӡ����
	sweep_mine(show, mine, ROW, COL);
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:1(Y) 0(N)\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			system("cls");
			printf("Game Start!\n");
			game();
			break;
		case 0:
			system("cls");
			printf("���˳�\n");
			break;
		default:
			system("cls");
			printf("������1��0\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}