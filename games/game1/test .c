#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"//�����Խ�ͷ�ļ�

void menu()
{
	printf("***************************************\n");
	printf("*********       ������        *********\n");
	printf("*********       1. play       *********\n");
	printf("*********       0. exit       *********\n");
	printf("***************************************\n");
}

void game()
{
	char judge = 0;
	char board[ROW][COL];//����
	init_board(board, ROW, COL);//���ú�����ʼ�����̣����飩ȫΪ�ո�
	print_board(board, ROW, COL);//��ӡ����
	while (1)
	{
		player_turn(board, ROW, COL);//�������
		print_board(board, ROW, COL);
		judge = is_win(board, ROW, COL);//�ж���Ϸ״��
		if (judge != 'c')//����ֵ��c��e��*��#
		{                //c����������e��������
			break;       //*�����ʤ����#������ʤ��
		}                //��ô���ĵ��Բ��������8��bushi��
		pc_turn(board, ROW, COL);//��������
		print_board(board, ROW, COL);//�ٴδ�ӡ����
		judge = is_win(board, ROW, COL);
		if (judge != 'c')
		{
			break;
		}
	}
	if (judge == '*')//�ж�����ѭ��������
		printf("��Ӯ����\n");
	else if (judge == '#')
		printf("ѷ��\n");
	else if (judge == 'e')
	{
		printf("ƽ����\n");
	}
}

void test()
{                                    //��ָ��(NULL)����time()���ص�ǰʱ��
	srand((unsigned int)time(NULL));//unsigned intת�����ظ�ʽ���⾯��
	int input = 0;
	do 
	{
		menu();
		printf("�Ƿ�ʼ��Ϸ1��Y����0��N����\n");
		scanf("%d", &input);//����input
		switch (input)
		{
		case 1:
			printf("��Ϸ��ʼ����\n");
			game();//����game������������Ϸ
			break;
		case 0:
			printf("���˳���\n");
			break;
		default:
			printf("������1��0��\n");
			break;
		}
	} while (input);//0Ϊ�ٷ�0Ϊ�棬1��0����Ʊ��ڼ���ѡ��ͽ���
}

int main()//�������������ݲ���
{
	test();//����test����
	return 0;
}