#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



//int ways(int n)
//{
//    if (n > 1)
//    {
//        return ways(n - 1) + ways(n - 2);
//    }
//    
//    return 1;
//    
//}
//
//int main()
//{
//    int n = 0;
//    int way = 0;
//    scanf("%d", &n);
//    way = ways(n);
//    printf("%d\n", way);
//    return 0;
//}

//void judge(int m, int n)
//{
//	int bit = sizeof(int) * 8;
//	int tmp = m ^ n;
//	int same = 0;
//	int differ = 0;
//
//	for (int i = 1; i <= bit; i++)
//	{
//		if ((tmp) & 1 == 1)
//		{
//			differ++;
//		}
//		else
//		{
//			same++;
//		}
//		tmp >>= 1;
//	}
//	printf("same:%d differ:%d\n", same, differ);
//}
//
//int main()
//{
//	int m = 0;
//	int n = 0;
//	scanf("%d %d", &m, &n);
//	judge(m, n);
//	return 0;
//}

//void format_change(int input, int bit)
//{
//	int Odd = 0;
//	int Even = 0;
//	int tmp = 0;
//
//	printf("Odd digits:");
//	for (int i = bit - 2; i >= 0; i-=2)
//	{
//		tmp = input >> i;
//		if ((tmp & 1) == 0)
//		{
//			printf("0");
//		}
//		else
//		{
//			printf("1");
//		}
//	}
//
//	printf("\n");
//
//	printf("Even digits:");
//	for (int i = bit - 1; i >= 0; i -= 2)
//	{
//		tmp = input >> i;
//		if ((tmp & 1) == 0)
//		{
//			printf("0");
//		}
//		else
//		{
//			printf("1");
//		}
//	}
//	printf("\n");
//}
//
//int main()
//{
//	int input = 0;
//	int bit = sizeof(input) * 8;
//	scanf("%d", &input);
//	format_change(input, bit);
//	return 0;
//}

//void judge_1(int input, int bit)
//{
//	int count = 0;
//
//	for (int i = 1; i <= bit; i++)
//	{
//		if ((input & 1) == 1)
//		{
//			count++;
//		}
//		input >>= 1;
//	}
//	printf("%d\n", count);
//}
//
//int main()
//{
//	int input = 0;
//	scanf("%d", &input);
//	int bit = sizeof(input) * 8;
//	judge_1(input, bit);
//	return 0;
//}

//void exchange(int a, int b)
//{
//	printf("a=%d b=%d\n", a, b);
//	a = a ^ b;
//	b = a ^ b;
//	a = a ^ b;
//	printf("a=%d b=%d\n", a, b);
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d %d", &a, &b);
//	exchange(a, b);
//	return 0;
//}