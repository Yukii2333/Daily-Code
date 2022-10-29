#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

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

int is_leap_year(int x)//简化
{
	return ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0));
}

int main()
{
	int y = 0;
	for (y = 1000; y <= 2000; y++)
	{
		if (is_leap_year(y))//判断y是否为闰年，是返回1，否返回0
		{
			printf("%d,", y);
		}
	}

	return 0;
}