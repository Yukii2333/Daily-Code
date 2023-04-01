#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void my_strncat(char* str1, const char* str2, size_t len)
{
	int i = 0;
	int j = 0;
	for (i = 0;; i++)
	{
		if (*(str1 + i) == '\0')
		{
			break;
		}
	}
	for (j = 0; j < len; j++)
	{
		*(str1 + i + j) = *(str2 + j);
	}
	*(str1 + i + j + 1) = '\0';
}

int main()
{
	char arr1[20] = "hello";
	char arr2[20] = " world!";
	my_strncat(arr1, arr2, 7);
	printf("%s\n", arr1);
	return 0;
}

//void my_strncpy(char* str1, const char* str2, size_t len)
//{
//	int i = 0;
//	for (i = 0; i < len; i++)
//	{
//		*(str1 + i) = *(str2 + i);
//	}
//	*(str1 + i + 1) = '\0';
//}
//
//int main()
//{
//	char arr1[] = "hello world!";
//	char arr2[10] = { 0 };
//	my_strncpy(arr2, arr1, 8);
//	printf("%s", arr2);
//	return 0;
//}

//void find_once_number(int* p, int sz)
//{
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	int arr[2] = { 0 };
//	for (i = 0; i < sz; i++)
//	{
//		int count = 0;
//		for (j = 0; j < sz; j++)
//		{
//			if (*(p + i) == *(p + j) && i != j)
//			{
//				count++;
//			}
//		}
//		if (count == 0)
//		{
//			arr[k] = *(p + i);
//			k++;
//		}
//	}
//	for (i = 0; i < k; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,1,2,2,3,4,5,5,6,6 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	find_once_number(arr, sz);
//	return 0;
//}