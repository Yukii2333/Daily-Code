#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

int is_prime(int i)//void xxx(int i)
{
	
	for (int n = 2; n <= sqrt(i); n++)
	{
		if (i % n == 0)
		{
			return 0;
		}
	}

	return 1;
}

int main()
{
	
	for (int i = 100; i <= 200; i++)
	{
	
		if (is_prime(i))
		{
			printf("%d,",i);
		}
	}

	return 0;
}

//int is_leap_year(y)
//{
//	return((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
//}
//
//int main()
//{
//	int y = 0;
//	int x = 0;
//	scanf("%d", &y);
//
//	if (is_leap_year(y))
//	{
//		printf("yes");
//	}
//
//	else
//	{
//		printf("no");
//	}
//
//	return 0;
//}

//void swap(int* x, int* y)
//{
//	int temp = 0;
//	temp = *x;
//	*x = *y;
//	*y = temp;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	printf("初始：a=%d,b=%d\n", a, b);
//	swap(&a, &b);
//	printf("交换后：a=%d,b=%d\n", a, b);
//	return 0;
//}

//void mul( a)
//{
//	short b = 0;
//
//	for (int i = 1; i <= a; i++)
//	{
//		
//		for (int c = 1; c <= a; c++)
//		{
//			b = i * c;
//			printf("%d*%d=%d,", i, c, b);
//		}
//	}
//
//	return 0;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	mul(a);//求输入数的乘法表函数mul
//	return 0;
//}

//int is_leap_year(int x)
//{
//	if (0 == x % 4)
//	{
//		if (x % 400 == 0)
//		{
//			return 1;
//		}
//		else if (x % 100 != 0)
//		{
//			return 1;
//		}
//		else
//		{
//			return 0;
//		}
//	}
//	else
//	{
//		return 0;
//	}
//
//}

//int is_leap_year(int x)//简化
//{
//	return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
//}
//
//int main()
//{
//	int y = 0;
//	for (y = 1000; y <= 2000; y++)
//	{
//		if (is_leap_year(y))//判断y是否为闰年，是返回1，否返回0
//		{
//			printf("%d,", y);
//		}
//	}
//
//	return 0;
//}