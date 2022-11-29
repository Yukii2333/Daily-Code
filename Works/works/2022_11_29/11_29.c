#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//void times_number(int arr[1000], int n)
//{
//	int tmp1 = 0;
//	int count = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		int tmp2 = 0;
//		for (j = 0; j < n; j++)
//		{
//			if (arr[j] == arr[i])
//			{
//				tmp2++;
//			}
//			if (count < tmp2)
//			{
//				tmp1 = arr[i];
//			}
//		}
//		if (count < tmp2)
//		{
//			count = tmp2;
//		}
//	}
//	printf("%d %d\n", tmp1, count);
//}
//
//int main()
//{
//	int arr[1000] = { 0 };
//	int N = 0;
//	scanf("%d", &N);
//	int i = 0;
//	for (i = 0; i < N; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	times_number(arr,N);
//	return 0;
}

//int is_prime(int n)//哥德巴赫的猜想，有缺陷
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(n); i++)
//	{
//		if (n % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int guess(int n)
//{
//	int i = 0;
//	int j = 0;
//	int count = 0;
//	if (n < 4)
//	{
//		return 0;
//	}
//	for (i = 2; i <= n / 2; i++)
//	{
//		for (j = 2; j < n; j++)
//		{
//			if (i + j == n && is_prime(i) && is_prime(j))
//			{
//				count++;
//			}
//		}
//	}
//	return count;
//}
//
//int main()
//{
//	int n =  1;
//	int ret[100] = { 0 };
//	int i = 0;
//	while (n)
//	{
//		scanf("%d", &n);
//		ret[i] = guess(n);
//		i++;
//	}
//	int j = 0;
//	for (j = 0; j < i - 1; j++)
//	{
//		printf("%d\n", ret[j]);
//	}
//	return 0;
//}

//double function(double x)
//{
//	double y = pow(x, 5) - 2 * pow(x, 4) + pow(x, 2) - 3;
//	return y;
//}
//
//double appro(double s)
//{
//	double a = 0.0;
//	double b = 2.0;
//	double ret = function((a + b) / 2);
//	while (fabs (ret) > s)
//	{
//		double tmp1 = function(a);
//		double tmp2 = function(b);
//		if (ret > 0)
//		{
//			if (tmp1 > 0)
//			{
//				a = (a + b) / 2;
//			}
//			else
//			{
//				b = (a + b) / 2;
//			}
//		}
//		else
//		{
//			if (tmp1 < 0)
//			{
//				a = (a + b) / 2;
//			}
//			else
//			{
//				b = (a + b) / 2;
//			}
//		}
//		ret = function((a + b) / 2);
//	}
//	return (a + b) / 2;
//}
//
//int main()
//{
//	double s = 0;
//	scanf("%lf", &s);
//	double x = appro(s);
//	printf("%.8f", x);
//	return 0;
//}

//int both_odd_even(int n)
//{
//	int flag1 = 0;
//	int flag2 = 0;
//	while (n)
//	{
//		if ((n % 10) % 2 == 0)//判断n的个位是否为偶数
//		{
//			flag1++;
//		}
//		if ((n % 10) % 2 == 1)//是否为奇数
//		{
//			flag2++;
//		}
//		n /= 10;//整形n /10则为去掉个位的新整数
//	}
//	if (flag1 > 0 && flag2 > 0)
//	{
//		return 1;
//	}
//	return 0;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	if (both_odd_even(n))
//	{
//		printf("%d YES\n", n);
//	}
//	else
//	{
//		printf("%d NO\n", n);
//	}
//	return 0;
//}