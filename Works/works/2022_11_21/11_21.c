#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>
#include <math.h>

//int main()
//{
//	int a = 0;
//	int n = 0;
//	int Sn = 0;
//	scanf("%d %d", &a, &n);
//	for (int i = 0; i < n; i++)
//	{
//		Sn += (a * pow(a, i));
//	}
//	printf("%d\n", Sn);
//	return 0;
//}

//int is_daffodil_number(int i)
//{
//	int sum = 0;
//	int one = i % 10;
//	int ten = (i / 10) % 10;
//	int hun = (i / 100) % 10;
//	int th = (i / 1000);
//	sum = pow(one, 3) + pow(ten, 3) + pow(hun, 3) + pow(th, 3);
//	if (sum == i)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int i = 0;
//	for (i = 1; i < 10000; i++)
//	{
//		if (is_daffodil_number(i))
//		{
//			printf("%d ", i);
//		}
//	}
//	
//}

//void print_shape(int n)
//{
//	int tmp = 1;
//	int tmp2 = n - 1;
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = tmp2; j > 0; j--)
//		{
//			printf(" ");
//		}
//		for (k = 0; k < tmp; k++)
//		{
//			printf("*");
//		}
//		for (j = tmp2; j > 0; j--)
//		{
//			printf(" ");
//		}
//		printf("\n");
//		tmp += 2;
//		tmp2--;
//	}
//	tmp2 = 1;
//	for (i = 0; i < n - 1; i++)
//	{
//		for (j = 0; j < tmp2; j++)
//		{
//			printf(" ");
//		}
//		for (k = tmp - 4; k > 0; k--)
//		{
//			printf("*");
//		}
//		for (j = 0; j < tmp2; j++)
//		{
//			printf(" ");
//		}
//		printf("\n");
//		tmp -= 2;
//		tmp2++;
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	print_shape(n);
//	return 0;
//}

//void upside_down(char* arr, int len)
//{
//	char tmp = 0;
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		tmp = *(arr + i);
//		*(arr + i) = *(arr + len - 1);
//		*(arr + len - 1) = tmp;
//		len--;
//	}
//}
//
//int main()
//{
//	char arr[100] = " ";
//	gets(arr);
//	int len = strlen(arr);
//	upside_down(arr, len);
//	printf("%s\n", arr);
//	return 0;
//}