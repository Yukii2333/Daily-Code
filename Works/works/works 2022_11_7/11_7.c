#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int arr[10] = { 0 };
	return 0;
}

//int number(int z)//数鸡蛋
//{
//	int num = 0;
//
//	for (int i = 0;; i++)
//	{
//		
//		if (i % 3 == 1 && i % 5 == z && i % 7 == 3)
//		{
//			return i;
//		}
//
//	}
//
//}
//
//int main()
//{
//	int y = 0;
//	int z = 0;
//	int i_v = 0;
//	scanf("%d %d", &y, &z);
//	i_v = number(z) + y;
//	printf("%d\n", i_v);
//	return 0;
//}

//void average(double arr[], int n)//调和平均数
//{
//	double sum = 0.0;
//	double ave = 0.0;
//	double result = 0.0;
//	
//	for (int i = 0; i < n; i++)
//	{
//		double tmp = 1.0 / arr[i];
//		sum = sum + tmp;
//	}
//
//	ave = sum / n;
//	result = 1.0 / ave;
//	printf("%.2lf\n", result);
//}
//
//int main()
//{
//	int n = 0;
//	double arr[1000] = { 0 };
//	scanf("%d", &n);
//
//	for (int i = 0; i < n; i++)
//	{
//		scanf("%lf", &arr[i]);
//	}
//
//	average(arr, n);
//	return 0;
//}

//void date(int d)//春夏秋冬
//{
//	int D = d % 100;
//
//	if (D >= 3 && D <= 5)
//	{
//		printf("spring\n");
//	}
//	else if (D >= 6 && D <= 8)
//	{
//		printf("summer\n");
//	}
//	else if (D >= 9 && D <= 11)
//	{
//		printf("autumn\n");
//	}
//	else
//	{
//		printf("winter\n");
//	}
//
//}
//
//int main()
//{
//	int d = 0;
//	scanf("%d", &d);
//	date(d);
//	return 0;
//}

//void date(int x)//星期
//{
//	switch (x)
//	{
//	case 1:
//		printf("Monday\n");
//		break;
//	case 2:
//		printf("Tuesday\n");
//		break;
//	case 3:
//		printf("Wednesday\n");
//		break;
//	case 4:
//		printf("Thursday\n");
//		break;
//	case 5:
//		printf("Friday\n");
//		break;
//	case 6:
//		printf("Saturday\n");
//		break;
//	case 7:
//		printf("Sunday\n");
//		break;
//	default:
//		printf("输入错误！\n");
//		break;
//	}
//}
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	date(x);
//	return 0;
//}