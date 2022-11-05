#define _CRT_SECURE_NO_WARNINGS 1

#include <Stdio.h>
#include <math.h>
#include <string.h>

//int main()
//{
//	int n = 0;
//	int arr[10] = { 1, 2, 4, 6, 7, 9, 14, 17, 20, 25 };
//	int right = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	scanf("%d", &n);
//	
//	while (right >= left)
//	{
//		int mid = (right + left) / 2;
//
//		if (arr[mid] > n)
//		{
//			right = mid - 1;
//		}
//		else if (arr[mid] < n)
//		{
//			left = mid + 1;
//		}
//		else if (arr[mid] == n)
//		{
//			printf("找到了是arr[%d]\n", mid);
//			return 0;
//		}
//
//	}
//
//	printf("找不到\n");
//	return 0;
//}

//int main()
//{
//	int count = 0;
//
//	for (int i = 1; i <= 100; i++)
//	{
//		if (i % 10 == 9)
//		{
//			count++;
//		}
//		if (i / 10 == 9)
//		{
//			count++;
//		}
//	}
//
//	printf("%d\n", count);
//	return 0;
//}

//int main()
//{
//	double r = 0.0;
//
//	for (int i = 1; i <= 100; i++)
//	{
//		double tmp = 0.0;
//
//		if (i % 2 == 0)
//		{
//			r = r + 1.0 / (-i);
//		}
//		else
//		{
//			r = r + 1.0 / i;
//		}
//
//	}
//
//	printf("%lf\n", r);
//	return 0;
//}

//int main()
//{
//	int arr[10] = { 0 };
//	int max = 0;
//
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//
//	max = arr[0];
//
//	for (int i = 0; i < 10; i++)
//	{
//
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//
//	}
//
//	printf("%d\n", max);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d %d", &n, &k);
//
//	for (int i = 1; i <= n; i++)
//	{
//
//		for (int j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%2d  ", i, j, i * j);
//		}
//
//		printf("\n");
//	}
//
//	return 0;
//}

//int main()
//{
//	int max = 0;
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//
//	for (int i = 1; i <= a; i++)
//	{
//
//		if (a % i == 0)
//		{
//
//			for (int j = 1; j <= b; j++)
//			{
//
//				if (b % j == 0)
//				{
//
//					if (j == i)
//					{
//						max = i;
//					}
//
//				}
//
//			}
//
//		}
//
//	}
//
//	printf("%d\n", max);
//	return 0;
//}

//int main()
//{
//
//	for (int i = 1000; i <= 2000; i++)
//	{
//		if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
//		{
//			printf("%d ", i);
//		}
//	}
//
//	return 0;
//}

//int main()
//{
//	int j = 0;
//	
//	for (int i = 100; i <= 200; i++)
//	{
//	
//		for (j = 2; j <= i; j++)
//		{
//			if (i % j == 0)
//			{
//				break;
//			}
//		}
//		
//		if (j == i)
//		{
//			printf("%d ", i);
//		}
//
//	}
//
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//	int tmp = 0;
//	scanf("%d %d %d", &a, &b, &c);
//
//	if (a < b)
//	{
//		tmp = a;
//		a = b;
//		b = tmp;
//	}
//	if (a < c)
//	{
//		tmp = a;
//		a = c;
//		c = tmp;
//	}
//	if (b < c)
//	{
//		tmp = b;
//		b = c;
//		c = tmp;
//	}
//
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	for (int i = 1; i <= 100; i++)
//	{
//
//		switch (i % 3)
//		{
//			case 0:
//				printf("%d ", i);
//				break;
//			default:
//				break;
//		}
//
//	}
//
//	return 0;
//}

//int main()
//{
//    int a = 0;
//    int b = 0;
//    scanf("%d %d", &a, &b);
//
//    if (a >= b)
//    {
//        printf("%d\n", a);
//    }
//    else
//    {
//        printf("%d\n", b);
//    }
//        return 0;
//}