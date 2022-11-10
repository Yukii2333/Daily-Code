#define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"

void menu()//菜单
{
	printf("**************************************\n");
	printf("**********   Minesweeper   ***********\n");
	printf("************   1. Play   *************\n");
	printf("************   0. Exit   *************\n");
	printf("**************************************\n");
}

void game()
{
	srand((unsigned int)time(NULL));//雷盘上的1表示雷
	char mine[ROWS][COLS] = { 0 };  //布置雷的棋盘
	char show[ROWS][COLS] = { 0 };  //展示给玩家的棋盘
								      //通过0和*来让两个棋盘分别初始化
	init_board(mine, ROWS, COLS, '0');//初始化雷盘
	init_board(show, ROWS, COLS, '*');//初始化操作棋盘
	set_mine(mine, ROW, COL);//布置地雷
	//print_board(mine, ROW, COL);
	//print_board(show, ROW, COL);//打印棋盘
	sweep_mine(show, mine, ROW, COL);
}

void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请选择:1(Y) 0(N)\n");
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
			printf("已退出\n");
			break;
		default:
			system("cls");
			printf("请输入1或0\n");
			break;
		}
	} while (input);
}

int main()
{
	test();
	return 0;
}