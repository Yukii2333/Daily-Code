#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int zero_number(int n)
{
    if (n > 1)
    {
        return n + zero_number(n - 1);
    }
    return 1;
}

int main()
{
    int n = 0;
    scanf("%d", &n);
    int arr[3][3] = {0};
    int sum = zero_number(n - 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = i; j <= i; j++)
        {
            if (arr[i][j] == 0)
            {
                count++;
            }
        }
    }
    printf("%d %d\n", sum, count);
    if (count == sum)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return 0;
}

//int max(int n)
//{
//	if (n > 1)
//	{
//		return n + max(n / 2);
//	}
//}
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int sum = max(n);
//	printf("%d\n", sum);
//	return 0;
//}

//void double_find(int arr[100], int n);
//void print(int arr[100], int n);
//void sort(int arr[100], int n);
//void assign(int arr[100], int n);
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[100] = { 0 };
//	assign(arr, n);
//	sort(arr, n);
//	double_find(arr, n);
//	return 0;
//}
//
//void double_find(int arr[100], int n)
//{
//	int f = 0;
//	scanf("%d", &f);
//	int F[100] = { 0 };
//	for (int i = 0; i < f; i++)
//	{
//		scanf("%d", &F[i]);
//	}
//	print(arr, n);
//	for (int i = 0; i < f; i++)
//	{
//		int left = 0;
//		int right = n - 1;
//		int site = 0;
//		while (left <= right)
//		{
//			int mid = (left + right) / 2;
//			if (arr[mid] > F[i])
//			{
//				right = mid - 1;
//			}
//			if (arr[mid] < F[i])
//			{
//				left = mid + 1;
//			}
//			if (arr[mid] == F[i])
//			{
//				site = mid + 1;
//				break;
//			}
//			
//		}
//		printf("%d", site);
//		if (F[i + 1] != 0)
//		{
//			printf(" ");
//		}
//		if (F[i + 1] == 0)
//		{
//			printf("\n");
//		}
//	}
//}
//
//void print(int arr[100], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d", arr[i]);
//		if (n - i >= 2)
//		{
//			printf(" ");
//		}
//	}
//	printf("\n");
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
//void sort(int arr[100], int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = n - 1; i > 0; i--)
//	{
//		for (j = i - 1; j >= 0; j--)
//		{
//			if (arr[i] < arr[j])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[i];
//				arr[i] = tmp;
//			}
//		}
//	}
//}

//void print(int arr[100], int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void find(int arr[100], int n)
//{
//	int f = 0;
//	int F[100] = { 0 };
//	int i = 0;
//	int j = 0;
//	scanf("%d", &f);
//	for (i = 0; i < f; i++)
//	{
//		scanf("%d", &F[i]);
//	}
//	print(arr, n);
//	for (i = 0; i < f; i++)
//	{
//		int count = 0;
//		for (j = 0; j < n; j++)
//		{
//			count++;
//			if (F[i] == arr[j])
//			{
//				printf("%d", count);
//				break;
//			}
//			if (count == n && F[i] != arr[j])
//			{
//				printf("%d", 0);
//			}
//		}
//		if (F[i + 1] != 0)
//		{
//			printf(" ");
//		}
//	}
//}
//
//void sort(int arr[100], int n)
//{
//	int i = 0;
//	int j = 0;
//	for (i = n - 1; i >= 0; i--)
//	{
//		for (j = i - 1; j >= 0; j--)
//		{
//			int tmp = arr[i];
//			if (arr[i] < arr[j])
//			{
//				arr[i] = arr[j];
//				arr[j] = tmp;
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
//	int arr[100] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	assign(arr, n);
//	sort(arr, n);
//	find(arr, n);
//	return 0;
//}

//void print(int* arr, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (*(arr+i) != 0)
//		{
//			printf("%d", *(arr + i));
//		}
//		if (*(arr + i + 1) != 0)
//		{
//			printf(" ");
//		}
//		
//	}
//	printf("\n");
//}
//
//void Delete(int* arr, int n, int d)
//{
//	int de[100] = { 0 };
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	for (i = 0; i < d; i++)
//	{
//		scanf("%d", &de[i]);
//	}
//	for (i = 0; i < d; i++)
//	{	
//		for (j = de[i] - 1; j < n; j++)
//		{
//			*(arr + j) = *(arr + j + 1);
//		}
//	}
//}
//
//void assign(int* arr, int n)
//{
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &*(arr + i));
//	}
//}
//
//int main()
//{
//	int arr[100] = { 0 };
//	int n = 0;
//	scanf("%d", &n);
//	assign(arr, n);
//	int d = 0;
//	scanf("%d", &d);
//	Delete(arr, n, d);
//	print(arr, n);
//	return 0;
//}
