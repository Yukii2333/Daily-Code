#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()//打印菜单
{
	printf("**************************\n");
	printf("**** 1.Add    2.Del   ****\n");
	printf("**** 3.Search 4.Modify****\n");
	printf("**** 5.Show   6.Sort  ****\n");
	printf("**** 0.Exit           ****\n");
	printf("**************************\n");
}

int main()
{
	int input = 0;
	Contact con;//创建通讯录
	init_contact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1://添加
			system("cls");
			add_contact(&con);
			break;
		case 2://删除
			system("cls");
			del_contact(&con);
			break;
		case 3://查找
			system("cls");
			search_contact(&con);
			break;
		case 4://修改
			system("cls");
			modify_contact(&con);
			break;
		case 5://展示
			system("cls");
			show_contact(&con);
			break;
		case 6://排序
			system("cls");
			sort_contact(&con);
			break;
		case 0://退出
			system("cls");
			printf("已退出\n");
			break;
		default:
			system("cls");
			printf("选择有误！\n");
			break;
		}
	} while (input);
	return 0;
}