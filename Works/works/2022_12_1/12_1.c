//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <assert.h>
//
//int get_max(int* arr, const int max, int cmax)
//{
//	assert(arr != NULL);
//	cmax = *arr;
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		if (*(arr + i) > cmax && *(arr + i) != max)
//		{
//			cmax = *(arr + i);
//		}
//	}
//	return cmax;
//}
//
//int main()
//{
//	int max = 0;
//	int cmax = 0;
//	int arr[10] = { 0 };
//	int i = 0;
//	for (i = 0; i < 10; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	max = get_max(arr, max, max);
//	cmax = get_max(arr, max, cmax);
//	printf("max=%d,cmax=%d\n", max, cmax);
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[10][10] = { 0 };
//	int count = 0;
//	int i = 0;
//	int j = 0;
//	for (i = 0; i < n; i++)
//	{
//		for (j = 0; j <= i; j++)
//		{
//			count++;
//			arr[i][j] = count;
//		}
//	}
//	for (i = 0; i < n; i++)
//	{
//		printf(" ");
//		for (j = 0; j < n; j++)
//		{
//			if (arr[i][j] < 10)
//			{
//				printf(" ");
//				printf("%d", arr[i][j]);
//			}
//			if (arr[i][j] >= 10)
//			{
//				printf("%d", arr[i][j]);
//				if (j < n - 1)
//				{
//					printf(" ");
//				}
//			}
//			if (arr[i][j] < 10 && j < n - 1)
//			{
//				printf(" ");
//			}
//		}
//		printf("\n");
//	}
//	return 0;
//}

//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int arr[50] = { 0 };
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	int j = n - 1;
//	for (i = 0 ; i < j; i++, j--)
//	{
//		printf("%d %d\n", arr[i], arr[j]);
//	}
//	return 0;
//}