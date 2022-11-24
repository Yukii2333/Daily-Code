#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

//void sort_number(int arr[100], int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			int tmp = 0;
//			if (arr[i] % 2 == 0 && arr[ j ]%2 == 0 && arr[i] > arr[j])
//			{
//				tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//			if (arr[i] % 2 != 0 && arr[j] % 2 != 0 && arr[i] > arr[j])
//			{
//				tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}
//}
//
//void print(int arr[100], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//void classify_number(int arr[100], int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = i + 1; j < n; j++)
//		{
//			int tmp = 0;
//			if (arr[i] % 2 == 0)
//			{
//				tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}
//}
//
//void assign(int arr[100], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[100] = { 0 };
//	assign(arr, n);
//	classify_number(arr, n);
//	sort_number(arr, n);
//	print(arr, n);
//	return 0;
//}

//int is_daffodil_number(int i)
//{
//	int sum = 0;
//	int one = i % 10;
//	int ten = (i / 10) % 10;
//	int hun = (i / 100) % 10;
//	int th = (i / 1000);
//	int n = 0;
//	int tmp = i;
//	while (tmp)
//	{
//		tmp /= 10;
//		n++;
//	}
//	sum = pow(one, n) + pow(ten, n) + pow(hun, n) + pow(th, n);
//	if (sum == i)
//	{
//		return 1;
//	}
//	return 0;
//}
//
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
//}

//int main()
//{
//    int n = 0;
//    int m = 0;
//    scanf("%d %d", &n, &m);
//    int arr1[2][2] = { 0 };
//    int arr2[2][2] = { 0 };
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr1[i][j]);
//        }
//    }
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            scanf("%d", &arr2[i][j]);
//        }
//    }
//    int count = 0;
//    for (i = 0; i < n; i++)
//    {
//        for (j = 0; j < m; j++)
//        {
//            if (arr1[i][j] == arr2[i][j])
//            {
//                count++;
//            }
//        }
//    }
//    if (count == n * m)
//    {
//        printf("Yes\n");
//    }
//    else
//    {
//        printf("No\n");
//    }
//    return 0;
//}

//int zero_number(int n)
//{
//    if (n > 1)
//    {
//        return n + zero_number(n - 1);
//    }
//    return 1;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int arr[3][3] = { 0 };
//    int sum = zero_number(n - 1);
//    for (int i = 0; i < n; i++)
//    {
//        for (int j = 0; j < n; j++)
//        {
//            scanf("%d", &arr[i][j]);
//        }
//    }
//    int count = 0;
//    for (int i = 1; i < n; i++)
//    {
//        for (int j = 0; j < i; j++)
//        {
//            if (arr[i][j] == 0)
//            {
//                count++;
//            }
//        }
//    }
//    printf("%d %d\n", sum, count);
//    if (count == sum)
//    {
//        printf("YES\n");
//    }
//    else
//    {
//        printf("NO\n");
//    }
//    return 0;
//}