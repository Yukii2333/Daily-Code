#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

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