#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

void init(int a[])//��ʼ�����麯��
{
	printf("��ʼ��ǰ��\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");

	printf("��ʼ����\n");

	for (int i = 0; i < 10; i++)
	{
		a[i] = 0;
		printf("%d ", a[i]);
	}

	printf("\n");

}

void print(int a[])//��ӡ����
{

	for (int i = 0; i < 10; i++)
	{
		printf("a[%d]=%d ", i, a[i]);
	}

	printf("\n");
}

void as(int a[], int len)//��ֵ����
{
	printf("������%d�����֣�\n" , len + 1);
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &a[i]);
	}

}

void reverse(int a[],int len)//���ú���
{
	int left = 0;
	int right = len;
	printf("���ú�\n");

	while (left <= right)
	{
		int tmp = a[left];
		a[left] = a[right];
		a[right] = tmp;
		left++;
		right--;
	}

}

int main()
{
	int a[10];
	int len = sizeof(a) / sizeof(a[0]) - 1;
	init(a);
	as(a, len);
	print(a);
	reverse(a, len);
	print(a);
	return 0;
}

//void exchange(char a[], char b[])
//{
//	int left = 0;
//	int right = strlen(a);
//	char tmp = { 0 };
//
//	while (left <= right)
//	{
//		tmp = a[left];
//		a[left] = b[left];
//		b[left] = tmp;
//		left++;
//	}
//
//}
//
//int main()
//{
//	char a[] = "bit!!";
//	char b[] = "hello";
//	printf("��ʼ:a[]=%s  b[]=%s\n", a, b);
//	exchange(a, b);
//	printf("����:a[]=%s  b[]=%s\n", a, b);
//	return 0;
//}