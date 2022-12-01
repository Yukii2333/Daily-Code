#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>



#include<string.h>
#include<assert.h>
#include<stdlib.h> 
#define N 100

//void reverse_word(char* left, char* right)
//{
//    assert(left && right);
//    while (left < right)
//    {
//        char ret = *left;
//        *left = *right;
//        *right = ret;
//
//        left++;
//        right--;
//    }
//}
//
//void reverse(char* arr, int len)
//{
//    assert(arr != NULL);
//    reverse_word(arr, arr + len - 1);
//    while (*arr)
//    {
//        char* start = arr;
//        while (*arr != '\0' && *arr != ' ')
//        {
//            arr++;
//        }
//        reverse_word(start, arr - 1);
//        if (*start == ' ')
//        {
//            arr++;
//        }
//    }
//}
//
//int main()
//{
//    char arr[N];
//    gets(arr);
//    int len = strlen(arr);
//    reverse(arr, len);
//    printf("%s\n", arr);
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//#define N 100
//
//void sort_str(char* arr, int sz)
//{
//    int flag[N] = { 0 };
//    int i = 0;
//    int j = 0;
//    for (i = 0; i < sz; i++)
//    {
//        if (*(arr + i) != ' ')
//        {
//            flag[j]++;
//        }
//        else
//        {
//            j++;
//        }
//    }
//    int k = 0;
//    int flag2[N] = { 0 };
//    while (flag[k] != 0)
//    {
//        flag2[k] = flag[k];
//        if (k > 0)
//        {
//            flag2[k] += flag2[k - 1];
//        }
//        k++;
//
//    }
//    k--;
//
//    while (k == 0 && j == 0);
//    {
//        int tmp1 = 0;
//        int tmp2 = 0;
//        int tmp3 = k;
//        int tmp4 = j;
//        flag[j] = tmp2;
//        for (i = 0; i <= tmp2; i++)
//        {
//            flag2[tmp3] = tmp1;
//            printf("%c", *(arr + tmp1 + j));
//            tmp4--;
//            tmp3--;
//        }
//        printf(" ");
//        k--;
//        j--;
//    }
//}
//
//int main()
//{
//    char arr[N] = { 0 };
//    gets(arr);
//    int sz = sizeof(arr) / sizeof(arr[0]);
//    sort_str(arr, sz);
//    return 0;
//}

//int  black_hole_times(int n)
//{
//	int arr[4] = { 0 };
//	int i = 0;
//	int j = 0;
//	int tmp = 0;
//	int t = 4;
//	while (t--)
//	{
//		arr[i] = n % 10;
//		i++;
//		n /= 10;
//	}
//	for (i = 0; i < 4; i++)
//	{
//		for (j = i + 1; j < 4; j++)
//		{
//			if (arr[i] < arr[j])//由大到小排列
//			{
//				tmp = arr[i];
//				arr[i] = arr[j];
//				arr[j] = tmp;
//			}
//		}
//	}
//	int n1 = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];//小
//	int n2 = arr[0] * 1000 + arr[1] * 100 + arr[2] * 10 + arr[3];//大
//	return (n2 - n1);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	int arr[100] = { 0 };
//	int count2 = 0;
//	scanf("%d", &k);
//	while(k--)
//	{
//		int count = 0;
//		scanf("%d", &n);
//		while (n != 6174)
//		{
//			n = black_hole_times(n);
//			count++;
//		}
//		arr[count2] = count;
//		count2++;
//	}
//	for (int i = 0; i < count2; i++)
//	{
//		printf("%d\n", arr[i]);
//	}
//	return 0;
//}