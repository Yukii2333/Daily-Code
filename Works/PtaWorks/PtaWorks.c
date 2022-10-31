#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

int main()
{
	int n = 0, b = 0;
	scanf("%d", &n);

	for (int x = 1; x <= 20; x++)
	{

		for (int y = 1; y <= 33; y++)
		{

			for (int z = 3; z <= 300; z = z + 3)
			{

				if (x + y + z == 100 && 5 * x + 3 * y + z / 3 == 100)
				{

					if (b < n)
					{
						printf("%d %d %d", x, y, z);
						printf("\n");
						b = b + 1;
					}

				}

			}

		}

	}

	return 0;
}

//int is_primer(int m)
//{
//	int i = 0;
//
//	for (int n = 2; n <= sqrt(m); n++)
//	{
//		i = m % n;
//
//		if (i == 0)
//		{
//			return 0;
//		}
//
//	}
//
//	return 1;
//}
//
//int main()
//{
//	int m = 0;
//	int count = 0;
//	scanf("%d", &m);
//
//	for (int i = m - 1;i > 1; i--)
//	{
//
//		if(is_primer(i))
//		{ 
//			printf("%6d", i);
//			count++;
//		}
//
//		if (count == 10)
//		{
//			return 0;
//		}
//
//	}
//
//	return 0;
//}

//int main()
//{
//	int n, i, j;
//	scanf("%d", &n);
//
//	for (i = 1; i <= n; i++)
//	{
//
//		for (j = 1; j <= n - i; j++)
//		{
//			printf(" ");
//		}
//
//		for (j = 1; j <= 2 * i - 1; j++)
//		{
//			printf("*");
//		}
//
//		printf("\n");
//	}
//
//	return 0;
//}

//int main() 
//{
//    int a, b;
//    scanf("%d %d", &a, &b);
//
//    for (int i = 0; i < a; i++) 
//    {
//       
//        for (int j = 0; j < b; j++)
//        {
//            printf("*");
//        }
//
//            printf("\n");
//    }
//    return 0;
//}

//int f(int n)
//{
//	int flag = 1;
//	int i = 2;
//	
//	for (i = 2; i * i <= n; i++)//i*i<=n 代替 i<=sqrt(n),节省性能
//	{
//		
//		if (n % i == 0)
//		{
//			flag = 0;
//			break;
//		}
//
//	}
//
//	return flag;
//}
//
//int g(int* p, int i)//传入的i必须是质数
//{
//	int flag = 1;
//	
//	for (*p; *p % i == 0 && *p > i; *p /= i)//使用指针对主函数的n直接操作
//	{
//		printf("%d*", i);
//	}
//
//	if (*p == i)//当n==i时，分解已经完全
//	{
//		printf("%d", i);
//		flag = 0;
//	}
//
//	return flag;//返回值用以判断分解是否结束
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//
//	if (f(n))//如果是素数，直接输出本身
//	{
//		printf("%d=%d", n, n);
//		return 0;
//	}
//
//	else
//	{
//		printf("%d=", n);
//		int i = 2;
//		
//		for (i = 2;; i++)
//		{
//			
//			if (f(i))//再次调用f（）判断 i 是否为素数
//			{
//				
//				if (!g(&n, i))
//				{
//					break;
//				}
//
//
//			}
//
//		}
//
//		return 0;
//	}
//
//}

//int main()
//{
//	int odd = 0, even = 0;
//	int N = 0;
//	int n[1000] = { 0 };
//	scanf("%d", &N);
//
//	for (int i = 0; i < N; i++)
//	{
//		scanf("%d", &n[i]);
//	}
//
//	for (int i = 0; i < N; i++)
//	{
//
//		if (n[i] % 2 == 0)
//		{
//			even++;
//		}
//
//		else
//		{
//			odd++;
//		}
//
//	}
//
//	printf("%d %d\n", odd, even);
//
//	return 0;
//}

//int is_leap_year(int a)
//{
//	return ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0));
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//
//	if (a > 2000 && a <= 3000)
//	{
//
//		if (a - 4 >= 2000)
//		{
//
//			for (int i = 2004; i <= a; i++)
//			{
//
//				if (is_leap_year(i))
//				{
//					printf("%d\n", i);
//				}
//
//			}
//
//		}
//
//		else
//		{
//			printf("None");
//		}
//
//	}
//
//	else
//	{
//		printf("Invalid year!");
//	}
//
//	return 0;
//}

//void mul( a)
//{
//	short b = 0;
//
//	for (int i = 1; i <= a; i++)
//	{
//		
//		for (int c = 1; c <= i; c++)
//		{
//			b = i * c;
//			printf("%d*%d=%-4d", c, i, b);//%-4d意思是数字占四位、左对齐
//		}
//		if (i != a)
//		{
//			printf("\n");
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

//int main()
//{
//	int sc1 = 0, sc2 = 0, sc3 = 0, sc4 = 0, sc5 = 0;
//	float aver = 0;
//	scanf("%d %d %d %d %d", &sc1, &sc2, &sc3, &sc4, &sc5);
//	aver = (sc1 + sc2 + sc3 + sc4 + sc5) / 5.0;
//	printf("%.1f\n", aver);
//	return 0;
//}

//int main()
//{
//	int on = 0, te = 0, hu = 0, th = 0;
//	scanf("%d %d %d %d", &on, &te, &hu, &th);
//	int p = on + te * 10 + hu * 100 + th * 1000;
//	printf("%d\n", p);
//	return 0;
//}

//float S(float L1, float L2, float L3)
//{
//	float s = 0;
//	float c = (L1 + L2 + L3) / 2;
//	s = sqrt(c * (c - L1) * (c - L2) * (c - L3));
//	return s;
//}
//
//int main()
//{
//	float L1 = 0, L2 = 0, L3 = 0;
//	float s = 0;
//	scanf("%f,%f,%f", &L1, &L2, &L3);
//	s = S(L1, L2, L3);
//	printf("%.2f\n", s);
//	return 0;
//}

//int main()
//{
//	int V = 0;
//	int L = 0, W = 0, H = 0;
//	scanf("%d %d %d", &L, &W, &H);
//	V = L * W * H;
//	printf("%d\n", V);
//	return 0;
//}

//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	b = a * a * a;
//	printf("%d\n", b);
//	return 0;
//}

//int add(a)
//{
//	int b = 0;
//
//	for (int i = 1; i <= a; i++)
//	{
//		b = b + i;
//	}
//
//	return b;
//}
//
//int main()
//{
//	int a = 0;
//	scanf("%d", &a);
//	int sum = add(a);
//	printf("%d", sum);
//	return 0;
//}