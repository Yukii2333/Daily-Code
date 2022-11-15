#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


void positive_number(int arr[10][10], int M, int N)
{
    int sum = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] > 0)
            {
                sum += arr[i][j];
            }
        }
    }
    printf("%d\n", sum);
}

void assign(int arr[10][10], int N)
{
    int i = 0;
    int j = 0;
    int tmp = N;
    while (tmp >= 1)
    {
        for (i = 0; i < N; i++)
        {
            scanf("%d", &arr[j][i]);
        }
        j++;
        tmp--;
    }
}

int main()
{
    int M = 0;
    int N = 0;
    scanf("%d %d", &M, &N);
    int arr[10][10] = { 0 };
    assign(arr, N);
    positive_number(arr, M, N);

    return 0;
}

//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <math.h>
//
//double dist(int x, int y)
//{
//	double distance = sqrt(x*x + y*y);
//	return distance;
//}
//
//int main()
//{
//	int x = 0;
//	int y = 0;
//	double ret = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		scanf("%d %d", &x, &y);
//		ret += dist(x, y);
//	}
//	printf("distance = %lf\n", ret);
//	return 0;
//}

//void up_average(int arr[3][4])
//{
//	double s = 0;
//	int n = 0;
//	int tmp = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			tmp += arr[i][j];
//		}
//	}
//	double ave = tmp / 12.0;
//	
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			if (arr[i][j] >= ave)
//			{
//				s += arr[i][j];
//				n++;
//			}
//		}
//	}
//	printf("s=%lf,n=%d\n", s, n);
//}
//
//void assign(int arr[3][4])
//{
//	int i = 0;
//	for (i = 0; i < 4; i++)
//	{
//		scanf("%d", &arr[0][i]);
//	}
//	for (i = 0; i < 4; i++)
//	{
//		scanf("%d", &arr[1][i]);
//	}
//	for (i = 0; i < 4; i++)
//	{
//		scanf("%d", &arr[2][i]);
//	}
//}
//
//int main()
//{
//	int arr[3][4] = { 0 };
//	assign(arr);
//	up_average(arr);
//	return 0;
//}

//void print(int point[100], int N)
//{
//	for (int i = 0; i < N; i++)
//	{
//		printf("%d\n", point[i]);
//	}
//}
//
//void answer(int arr[100], int M, int N)
//{
//	for (int i = 0; i < M; i++)
//	{
//		arr[i] = rand() % 2;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void judge(int arr1[100], int arr2[100], int arr3[100], int M, int N)
//{
//	int point[100] = { 0 };
//	int j = 0;
//	int tmp = N;
//	do
//	{
//		answer(arr3, M, N);
//		for (int i = 0; i < M; i++)
//		{
//			if (arr2[i] == arr3[i])
//			{
//				point[j] += arr1[i];
//			}
//		}
//		j++;
//		tmp--;
//	} while (tmp < 1);
//	print(point, N);
//}
//
//void solution(int arr[100], int M)
//{
//	for (int i = 0; i < M; i++)
//	{
//		arr[i] = rand() % 2;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//void score(int arr[100], int M)
//{
//	for (int i = 0; i < M; i++)
//	{
//		arr[i] = rand() % 5 + 1;
//		printf("%d ", arr[i]);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	srand((unsigned int)time(NULL));
//	int N = 0;
//	int M = 0;
//	scanf("%d %d", &N, &M);
//	int arr1[100] = { 0 };
//	int arr2[100] = { 0 };
//	int arr3[100] = { 0 };
//	score(arr1, M);
//	solution(arr2, M);
//	judge(arr1, arr2, arr3, M, N);
//	return 0;
//}

//void is_daffodil_number(int x)
//{
//	int i = 0;
//	for (i = 100; i < x; i++)
//	{
//		int one = i % 10;
//		int ten = (i / 10) % 10;
//		int hundreds = i / 100;
//		int tmp = one * one * one + ten * ten * ten + hundreds * hundreds * hundreds;
//		if (tmp == i)
//		{
//			printf("%d ", tmp);
//		}
//	}
//}
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	is_daffodil_number(x);
//	return 0;
//}

//int how_many(int X);
//
//int main()
//{
//	int x = 0;
//	scanf("%d", &x);
//	int X = x * 10000000;
//	int set = how_many(X);
//	printf("%d\n", set);
//	return 0;
//}
//
//int how_many(int X)
//{
//	int count = 0;
//	for (int i = 1; i < X; i *= 2)
//	{
//		count++;
//	}
//	return count;
//}