#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int swap(char arr[], char arr2[], int size)
{
    int s = size - 3;
    for (int i = 0; i < size - 2; i++)
    {
        int count = 0;
        char t = arr[i];
        arr[i] = arr[size - 1 - s];
        arr[size - 1 - s] = t;
        s--;
        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i] == arr2[i])
                count++;
        }
        if (count == size - 1)
            return 1;
    }
    return 0;
}
int main()
{
    char s1[] = "ABCD";
    char s2[] = "CDAB";
    int size = strlen(s1);
    int ret = swap(s1, s2, size);
    printf("%d", ret);
    return 0;
}



//int left_handed(char* p1, char* p2, int size, int n)
//{
//	int left = n - 1;
//	int right = size - 1;
//	char tmp = 0;
//	int i = 0;
//	int count = 0;
//	int tmp2 = n;
//	while (tmp2 > 0)
//	{
//		while (left >= 0)
//		{
//			count = 0;
//			tmp = *(p1 + left);
//			*(p1 + left) = *(p1 + right);
//			*(p1 + right) = tmp;
//			left--;
//			right--;
//			for (i = 0; i < n; i++)
//			{
//				if (*(p1 + i) == *(p2)+i)
//				{
//					count++;
//				}
//			}
//			if (count == n)
//			{
//				return 1;
//			}
//		}
//		tmp2--;
//	}
//	return 0;
//}
//
//int main()
//{
//	char s1[10] = { 0 };
//	char s2[10] = { 0 };
//	scanf("%s", s1);
//	scanf("%s", s2);
//	int size = strlen(s1);
//	int n = size - 1;
//	//if (n > size)
//	//{
//	//	printf("请输入不大于%d的数\n", size);
//	//}
//	//else
//	//{
//	int ret = left_handed(s1, s2, size, n);
//	printf("%d\n", ret);
//	//	printf("%s", s1);
//	//}
//	return 0;
//}

//void find_number(int p[3][3], int k, int n)
//{
//	int i = 0;
//	int j = 0;
//	int tmp = 1;
//	for (i = 0; i < k; i++)
//	{
//		for (j = 0; j < k; j++)
//		{
//			if (p[i][j] == n)
//			{
//				printf("找到了，下标为(%d,%d)\n", i + 1, j + 1);
//				tmp = 0;
//			}
//		}
//	}
//	if (tmp)
//	{
//		printf("未找到\n");
//	}
//}
//
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 3;
//	int n = 0;
//	scanf("%d", &n);
//	find_number(arr, k, n);
//	return 0;
//}