#define _CRT_SECURE_NO_WARNINGS 1

#include "contact.h"

void menu()//��ӡ�˵�
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
	Contact con;//����ͨѶ¼
	init_contact(&con);//��ʼ��ͨѶ¼
	do
	{
		menu();
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1://���
			system("cls");
			add_contact(&con);
			break;
		case 2://ɾ��
			system("cls");
			del_contact(&con);
			break;
		case 3://����
			system("cls");
			search_contact(&con);
			break;
		case 4://�޸�
			system("cls");
			modify_contact(&con);
			break;
		case 5://չʾ
			system("cls");
			show_contact(&con);
			break;
		case 6://����
			system("cls");
			sort_contact(&con);
			break;
		case 0://�˳�
			system("cls");
			printf("���˳�\n");
			break;
		default:
			system("cls");
			printf("ѡ������\n");
			break;
		}
	} while (input);
	return 0;
}