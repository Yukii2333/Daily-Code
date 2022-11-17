#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int factorial(int n)
{
	if (n <= 1)
	{
		return 1;
	}
	return n * factorial(n - 1);
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	int ret = factorial(n);
	printf("%d\n", ret);
	return 0;
}

//int factorial(int n)
//{
//	int tmp = 1;
//	for (int i = n; i >= 1; i--)
//	{
//		tmp *= i;
//	}
//	return tmp;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = factorial(n);
//	printf("%d\n", ret);
//	return 0;
//}

//void reverse_string(char* string)
//{
//	int right = strlen(string) - 1;//-1，脚标从0开始
//	int left = *string;//存每次的首地址
//	*string = *(string + right);
//	*(string + right) = '\0';//终止
//	if (strlen(string + 1) > 1)
//	{
//		reverse_string(string + 1);
//	}
//	*(string + right) = left;
//}
//
//int main()
//{
//	char arr[] = "abcdef";
//	printf("%s\n", arr);
//	reverse_string(arr);
//	printf("%s\n", arr);
//	return 0;
//}

//int F_number(int n)
//{
//	if (n > 2)
//	{
//		return F_number(n - 1) + F_number(n - 2);
//	}
//	return 1;
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = F_number(n);
//	printf("%d\n", ret);
//	return 0;
//}

//int F_number(int n)
//{
//	int tmp1 = 1;
//	int tmp2 = 1;
//	for (int i = 0; i < n - 2; i++)
//	{
//		if (n <= 2)
//		{
//			return 1;
//		}
//		if (i % 2 == 0)
//		{
//			tmp1 += tmp2;
//		}
//		else
//		{
//			tmp2 += tmp1;
//		}
//	}
//	if (tmp1 > tmp2)
//	{
//		return tmp1;
//	}
//	return tmp2;
//}

//int main()
//{
//	int n= 0;
//	scanf("%d", &n);
//	int ret = F_number(n);
//	printf("%d\n", ret);
//	return 0;
//}



//void print(int arr[10][10], int m, int n)
//{
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < m; j++)
//        {
//            printf("%d ", arr[j][i]);
//        }
//        printf("\n");
//    }
//}
//
//void assign(int arr[10][10], int m, int n)
//{
//    int i = 0;
//    int j = 0;
//    int tmp = m;
//
//    while (tmp >= 1)
//    {
//        for (i = 0; i < n; i++)
//        {
//            scanf("%d", &arr[j][i]);
//        }
//        j++;
//        tmp--;
//    }
//}
//
//int main()
//{
//    int arr[10][10] = { 0 };
//    int m = 0;
//    int n = 0;
//    scanf("%d %d", &m, &n);
//    assign(arr, m, n);
//    print(arr, m, n);
//    return 0;
//}