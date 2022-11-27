#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <string.h>

size_t my_strlen(const char* str)
{
	assert(str != NULL);
	size_t count = 0;
	while (*str++)
	{
		count++;
	}
	return count;
}

int main()
{
	char arr[] = "abcdefg";
	printf("%d\n", my_strlen(arr));
	return 0;
}

//char* my_strcpy(char* dest, const char* src);
//
//int main()
//{
//	char arr1[] = "abcdefg";
//	char arr2[100] = {0};
//	printf("%s\n", my_strcpy(arr2, arr1));
//	printf("%s\n", arr2);
//	return 0;
//}
//
//char* my_strcpy(char* dest, const char* src)
//{
//	assert(dest != NULL && src != NULL);
//	char* tmp = dest;
//	while (*dest++ = *src++)
//	{
//		;
//	}
//	return tmp;
//}


//int main()
//{
//    int i = 0;
//    int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//    for (i = 0; i <= 12; i++)
//    {
//        arr[i] = 0;
//        printf("hello bit\n");
//    }
//    return 0;
//}