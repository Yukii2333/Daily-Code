#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
//
//int main()
//{
//	int c = 1;
//	int x = 0;
//	int y = 0;
//	int n = 0;
//	int arr[10][10] = { 0 };
//	scanf("%d", &n);
//	arr[x][y] = 1;
//	while (n * n != c)
//	{
//		while (y + 1 < n && !arr[x][y + 1])
//			arr[x][++y] = ++c;
//		while (x + 1 < n && !arr[x + 1][y])
//			arr[++x][y] = ++c;
//		while (y - 1 >= 0 && !arr[x][y - 1])
//			arr[x][--y] = ++c;
//		while (x - 1 >= 0 && !arr[x - 1][y])
//			arr[--x][y] = ++c;
//	}
//	for (x = 0; x < n; x++)
//	{
//		for (y = 0; y < n; y++)
//		{
//			printf("%3d", arr[x][y]);
//		}
//		printf("\n");
//	}
//	return 0;
//}