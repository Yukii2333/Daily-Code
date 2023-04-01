#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

char* my_strstr(const char* str1, const char* str2)
{
	int count = 0;
	int i = 0;
	char* tmp = str2;
	char* Return = 0;
	while (*(str2+i) != '\0')
	{
		i++;
	}
	int j = 0;
	while (count!=i)
	{
		count = 0;
		if (*(str1 + j) == *str2)
		{
			Return = str1 + j;
			for (int k = 0; k < i; k++)
			{
				if (*(str1 + j + k) == *(str2 + k))
				{
					count++;
				}
			}
		}
		j++;
	}
	if (count == i)
		return Return;
	else
		return NULL;
}

int main()
{
	char arr1[] = "hello world!";
	char arr2[] = "world";
	char* ret = my_strstr(arr1, arr2);
	printf("%s\n", ret);
	return 0;
}

//void mystrcat(char* str1, char* str2)
//{
//	while (*str1 != '\0')
//	{
//		str1++;
//	}
//	while (*str2 != '\0')
//	{
//		*str1 = *str2;
//		str1++;
//		str2++;
//	}
//	str1++;
//	*str1 = '\0';
//}
//
//int main()
//{
//	char arr1[20] = "hello";
//	char arr2[20] = " world!";
//	mystrcat(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}

//int mystrcmp(char* str1, char* str2)
//{
//	while (1)
//	{
//		if (*str1 == '\0' && *str2 != '\0')
//		{
//			return -1;
//		}
//		else if (*str2 == '\0' && *str1 != '\0')
//		{
//			return 1;
//		}
//		else if (*str2 == '\0' && *str1 == '\0')
//		{
//			return 0;
//		}
//		str1++;
//		str2++;
//	}
//}
//
//int main()
//{
//	char arr1[] = "hello world!";
//	char arr2[] = "hello";
//	int ret = mystrcmp(arr1, arr2);
//	printf("%d\n", ret);
//	return 0;
//}

//void mystrcpy(char* p1, const char* p2)
//{
//	while (*(p2) != '\0')
//	{
//		*p1 = *p2;
//		p1++;
//		p2++;
//	}
//	p1++;
//	*p1 = '\0';
//}
//
//int main()
//{
//	char arr1[] = "hello world!";
//	char arr2[20] = { 0 };
//	mystrcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

//int mystrlen(char* p)
//{
//	int i = 0;
//	int count = 0;
//	while (*(p + i) != '\0')
//	{
//		count++;
//		i++;
//	}
//	return count;
//}
//
//int main()
//{
//	char arr[] = "hello world!";
//	int len = mystrlen(arr);
//	printf("%d\n", len);
//	return 0;
//}