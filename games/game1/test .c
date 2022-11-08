#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"//包含自建头文件

void menu()
{
	printf("***************************************\n");
	printf("*********       三子棋        *********\n");
	printf("*********       1. play       *********\n");
	printf("*********       0. exit       *********\n");
	printf("***************************************\n");
}

void game()
{
	char judge = 0;
	char board[ROW][COL];//棋盘
	init_board(board, ROW, COL);//调用函数初始化棋盘（数组）全为空格
	print_board(board, ROW, COL);//打印棋盘
	while (1)
	{
		player_turn(board, ROW, COL);//玩家落子
		print_board(board, ROW, COL);
		judge = is_win(board, ROW, COL);//判断游戏状况
		if (judge != 'c')//返回值有c、e、*、#
		{                //c（继续），e（结束）
			break;       //*（玩家胜），#（电脑胜）
		}                //这么笨的电脑不会真会输8（bushi）
		pc_turn(board, ROW, COL);//电脑下棋
		print_board(board, ROW, COL);//再次打印棋盘
		judge = is_win(board, ROW, COL);
		if (judge != 'c')
		{
			break;
		}
	}
	if (judge == '*')//判断跳出循环后的情况
		printf("你赢了捏\n");
	else if (judge == '#')
		printf("逊！\n");
	else if (judge == 'e')
	{
		printf("平局捏\n");
	}
}

void test()
{                                    //空指针(NULL)，让time()返回当前时间
	srand((unsigned int)time(NULL));//unsigned int转换返回格式避免警告
	int input = 0;
	do 
	{
		menu();
		printf("是否开始游戏1（Y），0（N）：\n");
		scanf("%d", &input);//输入input
		switch (input)
		{
		case 1:
			printf("游戏开始了喵\n");
			game();//调用game函数即进入游戏
			break;
		case 0:
			printf("已退出喵\n");
			break;
		default:
			printf("请输入1或0喵\n");
			break;
		}
	} while (input);//0为假非0为真，1和0的设计便于继续选择和结束
}

int main()//主函数尽量内容不多
{
	test();//调用test函数
	return 0;
}